/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container
*/

#include "msf/msf.h"

void *obj_container_new(void)
{
    obj_container_t *st_obj_container = malloc(sizeof(obj_container_t));

    FAIL_IF(!st_obj_container, NULL);
    obj_container_ctor(st_obj_container);
    return ((void *)st_obj_container);
}

void obj_container_ctor(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;

    FAIL_IF_VOID(!st_obj_container);
    obj_ctor(st_obj_container, animated, sfTrue);
    st_obj_container->type = container;
    st_obj_container->objs = NULL;
    st_obj_container->vtable = obj_container_vtable_new();
    st_obj_container->physics = physics_new(obj_container);
    st_obj_container->dtor = obj_container_dtor;
}

void obj_container_dtor(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;

    obj_dtor(obj_container);
    list_destroy(st_obj_container->objs);
}

void obj_container_destroy(void *obj_container)
{
    obj_container_dtor(obj_container);
    free(obj_container);
}