/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** obj_met
*/

#include "msf/msf.h"

void obj_render(void *obj, hub_t *hub)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj || !hub || !((obj_t *)obj)->state);
    VFUNC(st_obj, render, hub);
    obj_move(obj, hub);
}

void obj_move(void *obj, hub_t *hub)
{
    obj_t *st_obj = (obj_t *)obj;
    obj_physics_t *st_physics = NULL;
    sfVector2f position;
    sfInt64 elapsed_sec = 0;

    FAIL_IF_VOID(!st_obj || !st_obj->physics || !hub);
    elapsed_sec = sfClock_getElapsedTime(hub->timer).microseconds;
    st_physics = st_obj->physics;
    if (!obj_apply_collision_with_all(hub, obj))
        st_physics->speed.y += st_obj->physics->gravity;
    position = VGET(st_obj, get_position);
    position.x += (st_physics->speed.x * elapsed_sec) / 1000000;
    position.y += (st_physics->speed.y * elapsed_sec) / 1000000;
    VFUNC(st_obj, set_position, position);
}

void obj_bounce(void *obj, float angle, float initial_speed)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj || !st_obj->physics);
    FAIL_IF_VOID(st_obj->physics->angle != 0);
    st_obj->physics->angle = angle;
    st_obj->physics->speed.x = initial_speed * cos(RAD(angle));
    st_obj->physics->speed.y = -initial_speed * sin(RAD(angle));
}

void obj_recenter_origin(void *obj)
{
    obj_t *st_obj = obj;
    sfVector2u size;
    sfVector2f origin;

    FAIL_IF_VOID(!st_obj || !st_obj->vtable);
    FAIL_IF_VOID(!st_obj->vtable->get_size || !st_obj->vtable->set_origin)
    size = VGET(st_obj, get_size);
    origin.x = size.x / 2;
    origin.y = size.y / 2;
    VFUNC(st_obj, set_origin, origin);
}

void obj_kill(void *obj)
{
    obj_t *st_obj = obj;

    st_obj->state = sfFalse;
    st_obj->is_alive = sfFalse;
}