/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** obj_met
*/

#include "msf/msf.h"

void obj_render(void *obj, void *hub)
{
    obj_t *st_obj = (obj_t *)obj;

    st_obj->render(hub, obj);
}