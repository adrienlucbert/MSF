/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_get
*/

#include "msf/msf.h"

sfFloatRect obj_container_get_box(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF(!st_obj_container, box);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_box)
            box = VGET(buffer, get_box);
        if (box.width != 0 || box.height != 0)
            return (box);
    }
    return (box);
}