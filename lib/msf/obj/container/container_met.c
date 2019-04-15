/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_met
*/

#include "msf/msf.h"

void obj_container_add_obj(void *obj_container, void *obj, char *label, int z)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;

    FAIL_IF_VOID(!st_obj_container || !obj);
    node_ctor(obj, label, NULL);
    list_append(&st_obj_container->objs, obj);
    obj_set_z_index(&st_obj_container->objs, obj, z);
}

void obj_container_render(void *obj_container, hub_t *hub)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;

    FAIL_IF_VOID(!st_obj_container);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        buffer->vtable->render(buffer, hub);
    }
}