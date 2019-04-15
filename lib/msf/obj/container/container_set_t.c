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
    obj_t *buffer = NULL;

    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        VFUNC(buffer, set_position, position);
    }
}

void obj_container_set_rotation(void *obj_container, float angle)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;

    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        VFUNC(buffer, set_rotation, angle);
    }
}

void obj_container_set_scale(void *obj_container, sfVector2f scale)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;

    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        VFUNC(buffer, set_scale, scale);
    }

}

void obj_container_set_size(void *obj_container, sfVector2u size)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;

    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        VFUNC(buffer, set_size, size);
    }
}