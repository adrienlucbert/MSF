/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_get_t
*/

#include "msf/msf.h"

sfVector2f obj_container_get_origin(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_obj_container, origin);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_origin)
            origin = VGET(buffer, get_origin);
        if (origin.x != 0 || origin.y != 0)
            return (origin);
    }
    return (origin);
}

sfVector2f obj_container_get_position(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    sfVector2f position = {0, 0};

    FAIL_IF(!st_obj_container, position);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_position)
            position = VGET(buffer, get_position);
        if (position.x != 0 || position.y != 0)
            return (position);
    }
    return (position);
}

float obj_container_get_rotation(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    float rotation = 0;

    FAIL_IF(!st_obj_container, rotation);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_position)
            rotation = VGET(buffer, get_rotation);
        if (rotation != 0)
            return (rotation);
    }
    return (rotation);
}

sfVector2f obj_container_get_scale(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    sfVector2f scale = {0, 0};

    FAIL_IF(!st_obj_container, scale);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_scale)
            scale = VGET(buffer, get_scale);
        if (scale.x != 0 || scale.y != 0)
            return (scale);
    }
    return (scale);
}

sfVector2u obj_container_get_size(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    sfVector2u size = {0, 0};

    FAIL_IF(!st_obj_container, size);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_size)
            size = VGET(buffer, get_size);
        if (size.x != 0 || size.y != 0)
            return (size);
    }
    return (size);
}