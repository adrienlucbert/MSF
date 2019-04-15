/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_get_s
*/

#include "msf/msf.h"

const sfTexture *obj_container_get_texture(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    const sfTexture *texture = NULL;

    FAIL_IF(!st_obj_container, texture);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_texture)
            texture = VGET(buffer, get_texture);
        if (texture)
            return (texture);
    }
    return (texture);
}