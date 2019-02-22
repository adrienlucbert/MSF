/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** input_vtable
*/

#include "msf/msf.h"

void *input_obj_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    input_obj_vtable_ctor(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void input_obj_vtable_ctor(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = input_obj_render;
    st_obj_vtable->set_fill_color = NULL;
    st_obj_vtable->set_origin = NULL;
    st_obj_vtable->set_outline_color = NULL;
    st_obj_vtable->set_outline_thickness = NULL;
    st_obj_vtable->set_position = NULL;
    st_obj_vtable->set_rotation = NULL;
    st_obj_vtable->set_scale = NULL;
    st_obj_vtable->set_size = NULL;
    st_obj_vtable->set_texture = NULL;
}

void input_vtable_destroy(void *obj_vtable)
{
    free(obj_vtable);
}