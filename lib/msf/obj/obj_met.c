/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** obj_met
*/

#include "msf/msf.h"
#include <stdio.h>

void obj_render(void *obj, hub_t *hub)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj || !hub);
    VFUNC(st_obj, render, hub);
    obj_move(obj, hub);
}

void obj_move(void *obj, hub_t *hub)
{
    obj_t *st_obj = (obj_t *)obj;
    obj_physics_t *st_physics = NULL;
    sfVector2f position;
    sfVector2f speed;

    FAIL_IF_VOID(!st_obj || !st_obj->physics);
    st_physics = st_obj->physics;
    position = VGET(st_obj, get_position);
    speed = st_physics->speed;
    if (!obj_collide_with_all(hub, obj)) {
        st_physics->speed.y += st_obj->physics->gravity;
    }
    position.x += st_physics->speed.x;
    position.y += st_physics->speed.y;
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

sfBool obj_collide(hub_t *hub, void *obj_a, void *obj_b)
{
    obj_t *st_obj_a = (obj_t *)obj_a;
    obj_t *st_obj_b = (obj_t *)obj_b;
    sfVector2f pos;

    FAIL_IF(st_obj_a == st_obj_b, sfFalse);
    FAIL_IF(!st_obj_a || !st_obj_a->physics, sfFalse);
    FAIL_IF(!st_obj_b || !st_obj_b->physics, sfFalse);
    FAIL_IF(!st_obj_b->is_collider, sfFalse);
    manifold_reset(hub->manifold, st_obj_a->physics, st_obj_b->physics);
    pos = VGET(st_obj_a, get_position);
    FAIL_IF(!manifold_collide(hub->manifold), sfFalse);
    pos.x -= hub->manifold->normal.y * hub->manifold->penetration;
    pos.y += hub->manifold->normal.x * hub->manifold->penetration;
    physics_repulse(hub->manifold);
    VFUNC(st_obj_a, set_position, pos);
    return (sfTrue);
}

sfBool obj_collide_with_all(hub_t *hub, void *obj)
{
    obj_t *begin = NULL;
    obj_t *curr = NULL;
    obj_t *next = NULL;
    sfBool collide = sfFalse;

    FAIL_IF(!hub || !hub->scenes, sfFalse);
    begin = ((scene_t *)hub->scenes)->objs;
    FAIL_IF(!begin, sfFalse);
    curr = begin;
    next = curr->next;
    while (next != begin) {
        if (obj_collide(hub, obj, curr))
            collide = sfTrue;
        curr = next;
        next = (obj_t *)next->next;
    };
    if (obj_collide(hub, obj, curr))
        collide = sfTrue;
    return (collide);
}

sfBool obj_collide_with_group(hub_t *hub, void *obj, int group)
{
    obj_t *begin = NULL;
    obj_t *curr = NULL;
    obj_t *next = NULL;
    sfBool collide = sfFalse;

    FAIL_IF(!hub || !hub->scenes, sfFalse);
    begin = ((scene_t *)hub->scenes)->objs;
    FAIL_IF(!begin, sfFalse);
    curr = begin;
    next = curr->next;
    while (next != begin) {
        if (curr->group == group && curr != obj && obj_collide(hub, obj, curr))
            return (sfTrue);
        curr = next;
        next = (obj_t *)next->next;
    };
    if (curr->group == group && curr != obj && obj_collide(hub, obj, curr))
        collide = sfTrue;
    return (collide);
}