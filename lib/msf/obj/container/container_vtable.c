/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_vtable
*/

#include "msf/msf.h"

void *obj_container_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    obj_container_vtable_ctor_met(st_obj_vtable);
    obj_container_vtable_ctor_set(st_obj_vtable);
    obj_container_vtable_ctor_get(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void obj_container_vtable_ctor_met(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = obj_container_render;
}

void obj_container_vtable_ctor_set(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->set_fill_color = NULL;
    st_obj_vtable->set_origin = obj_container_set_origin;
    st_obj_vtable->set_outline_color = NULL;
    st_obj_vtable->set_outline_thickness = NULL;
    st_obj_vtable->set_position = obj_container_set_position;
    st_obj_vtable->set_rotation = obj_container_set_rotation;
    st_obj_vtable->set_scale = obj_container_set_scale;
    st_obj_vtable->set_size = obj_container_set_size;
    st_obj_vtable->set_radius = NULL;
    st_obj_vtable->set_texture = obj_container_set_texture;
}

void obj_container_vtable_ctor_get(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->get_fill_color = NULL;
    st_obj_vtable->get_origin = obj_container_get_origin;
    st_obj_vtable->get_outline_color = NULL;
    st_obj_vtable->get_outline_thickness = NULL;
    st_obj_vtable->get_position = obj_container_get_position;
    st_obj_vtable->get_rotation = obj_container_get_rotation;
    st_obj_vtable->get_scale = obj_container_get_scale;
    st_obj_vtable->get_size = obj_container_get_size;
    st_obj_vtable->get_radius = NULL;
    st_obj_vtable->get_texture = obj_container_get_texture;
    st_obj_vtable->get_box = obj_container_get_box;
}