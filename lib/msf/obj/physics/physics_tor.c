/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** physics_tor
*/

#include "msf/msf.h"

void *physics_new(void *obj)
{
    obj_physics_t *physics = malloc(sizeof(obj_physics_t));

    FAIL_IF(!physics, NULL);
    physics_ctor(physics, obj);
    return ((void *)physics);
}

void physics_ctor(void *physics, void *obj)
{
    obj_physics_t *st_physics = (obj_physics_t *)physics;
    obj_t *st_obj = (obj_t *)obj;

    st_physics->angle = 0;
    st_physics->gravity = 0;
    st_physics->restitution = 0;
    st_physics->speed = (sfVector2f){0, 0};
    st_physics->mass = 1;
    st_physics->inv_mass = (st_physics->mass == 0 ? 0 : 1 / st_physics->mass);
    if (st_obj->vtable->get_size)
        st_physics->size = VGET(st_obj, get_size);
    else
        st_physics->size = (sfVector2u){0, 0};
    st_physics->pos = VGET(st_obj, get_position);
    st_physics->scale = VGET(st_obj, get_scale);
    if (st_obj->vtable->get_radius)
        st_physics->radius = VGET(st_obj, get_radius);
    else
        st_physics->radius = 0;
}

void physics_destroy(void *physics)
{
    free(physics);
}