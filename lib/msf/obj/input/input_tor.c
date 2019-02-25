/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** input_tor
*/

#include "msf/msf.h"

void *input_obj_new(void *background, void *foreground, sfVector2f pos)
{
    input_obj_t *st_input_obj = malloc(sizeof(input_obj_t));

    FAIL_IF(!st_input_obj, NULL);
    input_obj_ctor(st_input_obj, background, foreground, pos);
    return ((void *)st_input_obj);
}

void input_obj_ctor(void *input_obj, void *bck, void *frg, sfVector2f pos)
{
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;

    FAIL_IF_VOID(!st_input_obj);
    obj_ctor(st_input_obj, text, sfFalse);
    st_input_obj->vtable = input_obj_vtable_new();
    st_input_obj->dtor = input_obj_dtor;
    st_input_obj->foreground = frg;
    st_input_obj->background = bck;
    ((obj_t *)bck)->vtable->set_position(bck, pos);
    ((obj_t *)frg)->vtable->set_position(frg, pos);
}

void input_obj_dtor(void *input_obj)
{
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;

    obj_dtor(input_obj);
    if (st_input_obj->background) {
        ((obj_t *)st_input_obj->background)->dtor(st_input_obj->background);
        free(st_input_obj->background);
    }
    if (st_input_obj->foreground) {
        ((obj_t *)st_input_obj->foreground)->dtor(st_input_obj->foreground);
        free(st_input_obj->foreground);
    }
}

void input_obj_destroy(void *input_obj)
{
    input_obj_dtor(input_obj);
    free(input_obj);
}