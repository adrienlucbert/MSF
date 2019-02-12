/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** text_tor
*/

#include "msf/msf.h"

void *text_obj_new(char *str)
{
    text_obj_t *st_text_obj = malloc(sizeof(text_obj_t));

    FAIL_IF(!st_text_obj, NULL);
    text_obj_ctor(st_text_obj, str);
    return ((void *)st_text_obj);
}

void *text_obj_ctor(void *text_obj, char *str)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF(!st_text_obj, NULL);
    obj_ctor(st_text_obj, text);
    st_text_obj->text = sfText_create();
    st_text_obj->font = NULL;
    st_text_obj->color = sfBlack;
    st_text_obj->char_size = 20;
    st_text_obj->str = my_memdup(str, -1);
    st_text_obj->dtor = text_obj_dtor;
    return (text_obj);
}

void text_obj_dtor(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    obj_dtor(text_obj);
    sfText_destroy(st_text_obj->text);
    sfFont_destroy(st_text_obj->font);
    free(st_text_obj->str);
}

void text_obj_destroy(void *text_obj)
{
    text_obj_dtor(text_obj);
    free(text_obj);
}