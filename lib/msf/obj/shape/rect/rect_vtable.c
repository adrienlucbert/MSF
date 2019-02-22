/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_vtable
*/

#include "msf/msf.h"

void *rect_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    rect_vtable_ctor(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void rect_vtable_ctor(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = rect_render;
    st_obj_vtable->set_fill_color = rect_set_fill_color;
    st_obj_vtable->set_origin = NULL;
    st_obj_vtable->set_outline_color = rect_set_outline_color;
    st_obj_vtable->set_outline_thickness = rect_set_outline_thickness;
    st_obj_vtable->set_position = NULL;
    st_obj_vtable->set_rotation = NULL;
    st_obj_vtable->set_scale = rect_set_scale;
    st_obj_vtable->set_size = NULL;
    st_obj_vtable->set_texture = NULL;
    st_obj_vtable->get_fill_color = NULL;
    st_obj_vtable->get_origin = NULL;
    st_obj_vtable->get_outline_color = NULL;
    st_obj_vtable->get_outline_thickness = NULL;
    st_obj_vtable->get_position = NULL;
    st_obj_vtable->get_rotation = NULL;
    st_obj_vtable->get_scale = NULL;
    st_obj_vtable->get_size = NULL;
    st_obj_vtable->get_texture = NULL;
}

void rect_vtable_destroy(void *obj_vtable)
{
    free(obj_vtable);
}