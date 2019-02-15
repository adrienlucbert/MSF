/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** obj_set
*/

#include "msf/msf.h"

void obj_set_group(void *obj, int group)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj);
    st_obj->group = group;
}

void obj_set_state(void *obj, sfBool state)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj);
    st_obj->state = state;
}

void obj_set_speed(void *obj, float sx, float sy)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj);
    st_obj->speed.x = sx;
    st_obj->speed.y = sy;
}

void obj_set_pos(void *obj, float x, float y)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj);
    st_obj->pos.x = x;
    st_obj->pos.y = y;
}