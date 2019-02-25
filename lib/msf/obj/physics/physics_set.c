/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** physics_set
*/

#include "msf/msf.h"

void obj_physics_set_gravity(void *obj, float gravity)
{
    obj_t *st_obj = (obj_t *)obj;
    obj_physics_t *st_physics = NULL;

    FAIL_IF_VOID(!st_obj || !st_obj->physics);
    st_physics = (obj_physics_t *)st_obj->physics;
    st_physics->gravity = gravity;
}

void obj_physics_set_restitution(void *obj, float restitution)
{
    obj_t *st_obj = (obj_t *)obj;
    obj_physics_t *st_physics = NULL;

    FAIL_IF_VOID(!st_obj || !st_obj->physics);
    st_physics = (obj_physics_t *)st_obj->physics;
    st_physics->restitution = restitution;
}

void obj_physics_set_angle(void *obj, float angle)
{
    obj_t *st_obj = (obj_t *)obj;
    obj_physics_t *st_physics = NULL;

    FAIL_IF_VOID(!st_obj || !st_obj->physics);
    st_physics = (obj_physics_t *)st_obj->physics;
    st_physics->angle = angle;
}