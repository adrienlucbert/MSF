/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** animated_vtable
*/

#include "msf/msf.h"

void *anim_obj_vtable_new(void)
{
    obj_vtable_t *st_obj_vtable = malloc(sizeof(obj_vtable_t));

    FAIL_IF(!st_obj_vtable, NULL);
    anim_obj_vtable_ctor(st_obj_vtable);
    return ((void *)st_obj_vtable);
}

void anim_obj_vtable_ctor(void *obj_vtable)
{
    obj_vtable_t *st_obj_vtable = (obj_vtable_t *)obj_vtable;

    st_obj_vtable->render = anim_obj_render;
    st_obj_vtable->set_fill_color = NULL;
    st_obj_vtable->set_origin = anim_obj_set_origin;
    st_obj_vtable->set_outline_color = NULL;
    st_obj_vtable->set_outline_thickness = NULL;
    st_obj_vtable->set_position = anim_obj_set_position;
    st_obj_vtable->set_rotation = anim_obj_set_rotation;
    st_obj_vtable->set_scale = anim_obj_set_scale;
    st_obj_vtable->set_size = anim_obj_set_size;
    st_obj_vtable->set_texture = anim_obj_set_texture;
    st_obj_vtable->get_fill_color = NULL;
    st_obj_vtable->get_origin = anim_obj_get_origin;
    st_obj_vtable->get_outline_color = NULL;
    st_obj_vtable->get_outline_thickness = NULL;
    st_obj_vtable->get_position = anim_obj_get_position;
    st_obj_vtable->get_rotation = anim_obj_get_rotation;
    st_obj_vtable->get_scale = anim_obj_get_scale;
    st_obj_vtable->get_size = anim_obj_get_size;
    st_obj_vtable->get_texture = anim_obj_get_texture;
}

void anim_vtable_destroy(void *obj_vtable)
{
    free(obj_vtable);
}