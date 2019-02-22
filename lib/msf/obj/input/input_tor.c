/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** input_tor
*/

#include "msf/msf.h"

void *input_obj_new(void)
{
    input_obj_t *st_input_obj = malloc(sizeof(input_obj_t));

    FAIL_IF(!st_input_obj, NULL);
    input_obj_ctor(st_input_obj);
    return ((void *)st_input_obj);
}

void input_obj_ctor(void *input_obj)
{
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;

    FAIL_IF_VOID(!st_input_obj);
    obj_ctor(st_input_obj, text);
    st_input_obj->value = NULL;
    st_input_obj->dtor = input_obj_dtor;
}

void input_obj_dtor(void *input_obj)
{
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;

    obj_dtor(input_obj);
    if (st_input_obj->value)
        free(st_input_obj->value);
}

void input_obj_destroy(void *input_obj)
{
    input_obj_dtor(input_obj);
    free(input_obj);
}