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
    rect_vtable_ctor_met(st_obj_vtable);
    rect_vtable_ctor_set(st_obj_vtable);
    rect_vtable_ctor_get(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void rect_vtable_ctor_met(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = rect_render;
}

void rect_vtable_ctor_set(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->set_fill_color = rect_set_fill_color;
    st_obj_vtable->set_origin = rect_set_origin;
    st_obj_vtable->set_outline_color = rect_set_outline_color;
    st_obj_vtable->set_outline_thickness = rect_set_outline_thickness;
    st_obj_vtable->set_position = rect_set_position;
    st_obj_vtable->set_rotation = rect_set_rotation;
    st_obj_vtable->set_scale = rect_set_scale;
    st_obj_vtable->set_size = rect_set_size;
    st_obj_vtable->set_radius = NULL;
    st_obj_vtable->set_texture = rect_set_texture;
}

void rect_vtable_ctor_get(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->get_fill_color = rect_get_fill_color;
    st_obj_vtable->get_origin = rect_get_origin;
    st_obj_vtable->get_outline_color = rect_get_outline_color;
    st_obj_vtable->get_outline_thickness = rect_get_outline_thickness;
    st_obj_vtable->get_position = rect_get_position;
    st_obj_vtable->get_rotation = rect_get_rotation;
    st_obj_vtable->get_scale = rect_get_scale;
    st_obj_vtable->get_size = rect_get_size;
    st_obj_vtable->get_radius = NULL;
    st_obj_vtable->get_texture = rect_get_texture;
}

void rect_vtable_destroy(void *obj_vtable)
{
    free(obj_vtable);
}