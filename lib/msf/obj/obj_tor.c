/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** obj_tor
*/

#include "msf/msf.h"

void *obj_new(obj_type type, sfBool is_collider)
{
    obj_t *st_obj = malloc(sizeof(obj_t));

    FAIL_IF(!st_obj, NULL);
    obj_ctor(st_obj, type, is_collider);
    return ((void *)st_obj);
}

void obj_ctor(void *obj, obj_type type, sfBool is_collider)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj);
    st_obj->fixing = absolute;
    st_obj->type = type;
    st_obj->group = 0;
    st_obj->state = sfTrue;
    st_obj->vtable = NULL;
    st_obj->is_collider = is_collider;
    st_obj->mouse_evt = obj_mouse_evt_new();
    st_obj->physics = NULL;
    st_obj->dtor = obj_dtor;
}

void obj_dtor(void *obj)
{
    obj_t *st_obj = (obj_t *)obj;

    st_obj->state = sfFalse;
    obj_mouse_evt_destroy(st_obj->mouse_evt);
    if (st_obj->vtable)
        anim_vtable_destroy(st_obj->vtable);
    physics_destroy(st_obj->physics);
}

void obj_destroy(void *obj)
{
    obj_dtor(obj);
    free(obj);
}