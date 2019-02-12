/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** obj_tor
*/

#include "msf/msf.h"

static obj_render_method get_obj_render_method(obj_type type);

void *obj_new(obj_type type)
{
    obj_t *st_obj = malloc(sizeof(obj_t));

    FAIL_IF(!st_obj, NULL);
    obj_ctor(st_obj, type);
    return ((void *)st_obj);
}

static obj_render_method get_obj_render_method(obj_type type)
{
    obj_render_method methods[3];

    methods[0] = obj_text_render;
    methods[1] = obj_animated_render;
    methods[2] = obj_input_render;
    return (methods[type]);
}

void *obj_ctor(void *obj, obj_type type)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF(!st_obj, NULL);
    st_obj->fixing = absolute;
    st_obj->type = type;
    st_obj->group = 0;
    st_obj->state = sfTrue;
    st_obj->speed = vectorf_new(0, 0);
    st_obj->pos = vectorf_new(0, 0);
    st_obj->rotation = 0;
    st_obj->render = get_obj_render_method(type);
    return (obj);
}

void obj_dtor(void *obj)
{
    obj_t *st_obj = (obj_t *)obj;

    st_obj->state = sfFalse;
}

void obj_destroy(void *obj)
{
    obj_dtor(obj);
    free(obj);
}