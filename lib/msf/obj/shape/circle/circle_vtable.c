/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_vtable
*/

#include "msf/msf.h"

void *circle_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    circle_vtable_ctor_met(st_obj_vtable);
    circle_vtable_ctor_set(st_obj_vtable);
    circle_vtable_ctor_get(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void circle_vtable_ctor_met(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = circle_render;
}

void circle_vtable_ctor_set(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->set_fill_color = circle_set_fill_color;
    st_obj_vtable->set_origin = circle_set_origin;
    st_obj_vtable->set_outline_color = circle_set_outline_color;
    st_obj_vtable->set_outline_thickness = circle_set_outline_thickness;
    st_obj_vtable->set_position = circle_set_position;
    st_obj_vtable->set_rotation = circle_set_rotation;
    st_obj_vtable->set_scale = circle_set_scale;
    st_obj_vtable->set_size = circle_set_size;
    st_obj_vtable->set_radius = circle_set_radius;
    st_obj_vtable->set_texture = circle_set_texture;
}

void circle_vtable_ctor_get(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->get_fill_color = circle_get_fill_color;
    st_obj_vtable->get_origin = circle_get_origin;
    st_obj_vtable->get_outline_color = circle_get_outline_color;
    st_obj_vtable->get_outline_thickness = circle_get_outline_thickness;
    st_obj_vtable->get_position = circle_get_position;
    st_obj_vtable->get_rotation = circle_get_rotation;
    st_obj_vtable->get_scale = circle_get_scale;
    st_obj_vtable->get_size = circle_get_size;
    st_obj_vtable->get_radius = circle_get_radius;
    st_obj_vtable->get_texture = circle_get_texture;
    st_obj_vtable->get_box = circle_get_box;
}

void circle_vtable_destroy(void *obj_vtable)
{
    free(obj_vtable);
}