/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** mouse_evt
*/

#include "msf/msf.h"

void *obj_mouse_evt_new(void)
{
    obj_mouse_evt_t *st_mouse_evt = malloc(sizeof(obj_mouse_evt_t));

    FAIL_IF(!st_mouse_evt, NULL);
    obj_mouse_evt_ctor(st_mouse_evt);
    return ((void *)st_mouse_evt);
}

void obj_mouse_evt_ctor(void *mouse_evt)
{
    obj_mouse_evt_t *st_mouse_evt = (obj_mouse_evt_t *)mouse_evt;

    FAIL_IF_VOID(!mouse_evt);
    st_mouse_evt->focus = sfFalse;
    st_mouse_evt->hover = sfFalse;
    st_mouse_evt->active = sfFalse;
    st_mouse_evt->x = 0;
    st_mouse_evt->y = 0;
}

void obj_mouse_evt_destroy(void *mouse_evt)
{
    free(mouse_evt);
}