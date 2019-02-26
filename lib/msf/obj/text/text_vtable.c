/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** text_vtable
*/

#include "msf/msf.h"

void *text_obj_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    text_obj_vtable_ctor_met(st_obj_vtable);
    text_obj_vtable_ctor_set(st_obj_vtable);
    text_obj_vtable_ctor_get(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void text_obj_vtable_ctor_met(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;
    st_obj_vtable->render = text_obj_render;
}

void text_obj_vtable_ctor_set(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->set_fill_color = text_obj_set_fill_color;
    st_obj_vtable->set_origin = text_obj_set_origin;
    st_obj_vtable->set_outline_color = text_obj_set_outline_color;
    st_obj_vtable->set_outline_thickness = text_obj_set_outline_thickness;
    st_obj_vtable->set_position = text_obj_set_position;
    st_obj_vtable->set_rotation = text_obj_set_rotation;
    st_obj_vtable->set_scale = text_obj_set_scale;
    st_obj_vtable->set_size = text_obj_set_size;
    st_obj_vtable->set_radius = NULL;
    st_obj_vtable->set_texture = NULL;
}

void text_obj_vtable_ctor_get(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->get_fill_color = text_obj_get_fill_color;
    st_obj_vtable->get_origin = text_obj_get_origin;
    st_obj_vtable->get_outline_color = text_obj_get_outline_color;
    st_obj_vtable->get_outline_thickness = text_obj_get_outline_thickness;
    st_obj_vtable->get_position = text_obj_get_position;
    st_obj_vtable->get_rotation = text_obj_get_rotation;
    st_obj_vtable->get_scale = text_obj_get_scale;
    st_obj_vtable->get_size = text_obj_get_size;
    st_obj_vtable->get_radius = NULL;
    st_obj_vtable->get_texture = NULL;
    st_obj_vtable->get_box = text_obj_get_box;
}

void text_vtable_destroy(void *obj_vtable)
{
    free(obj_vtable);
}