/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_get_t
*/

#include "msf/msf.h"

sfVector2f obj_container_get_origin(void *obj_container)
{
    obj_container = obj_container;
    return (VECT2F(0, 0));
}

sfVector2f obj_container_get_position(void *obj_container)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj_container;
    obj_t *buffer = NULL;
    sfVector2f position = {0, 0};
    int check = 0;
    sfVector2f ret = VECT2F(0, 0);

    FAIL_IF(!obj_container, position);
    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        if (buffer->vtable->get_position) {
            position = VGET(buffer, get_position);
            ret = !check ? position : ret;
            check = 1;
        }
        if (position.x <= ret.x && position.y <= ret.y)
            ret = position;
    }
    return (ret);
}

float obj_container_get_rotation(void *obj_container)
{
    obj_container = obj_container;
    return (0);
}

sfVector2f obj_container_get_scale(void *obj_container)
{
    obj_container = obj_container;
    return (VECT2F(1, 1));
}

sfVector2u obj_container_get_size(void *obj_container)
{
    obj_container = obj_container;
    return (VECT2U(0, 0));
}