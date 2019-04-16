/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_set_t
*/

#include "msf/msf.h"

void obj_container_set_origin(void *obj_container, sfVector2f origin)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;

    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        VFUNC(buffer, set_origin, origin);
    }
}

void obj_container_set_position(void *obj_container, sfVector2f position)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    sfVector2f base;
    sfVector2f delta;
    sfVector2f relative;
    obj_t *buffer = NULL;

    base = VGET(st_obj_container->objs, get_position);
    delta.x = position.x - base.x;
    delta.y = position.y - base.y;
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_position) {
            relative = VGET(buffer, get_position);
            relative.x += delta.x;
            relative.y += delta.y;
            VFUNC(buffer, set_position, relative);
        }
    }
}

void obj_container_set_rotation(void *obj_container, float angle)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    float base;
    float delta;
    float relative;

    base = VGET(st_obj_container->objs, get_rotation);
    delta = angle - base;
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_rotation) {
            relative = VGET(buffer, get_rotation);
            relative += delta;
            VFUNC(buffer, set_rotation, angle);
        }
    }
}

void obj_container_set_scale(void *obj_container, sfVector2f scale)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    sfVector2f relative;

    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_scale) {
            relative = VGET(buffer, get_scale);
            relative.x += scale.x;
            relative.y += scale.y;
            VFUNC(buffer, set_scale, scale);
        }
    }

}

void obj_container_set_size(void *obj_container, sfVector2u size)
{
    obj_container = obj_container;
    size = size;
    return;
}