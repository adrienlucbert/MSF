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

void text_obj_ctor(void *text_obj, char *str)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    obj_ctor(st_text_obj, text);
    st_text_obj->text = sfText_create();
    text_obj_set_font(st_text_obj, NULL);
    text_obj_set_color(st_text_obj, sfBlack);
    text_obj_set_char_size(st_text_obj, 20);
    text_obj_set_string(st_text_obj, str);
    st_text_obj->render = text_obj_render;
    st_text_obj->dtor = text_obj_dtor;
}

void text_obj_dtor(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    obj_dtor(text_obj);
    sfText_destroy(st_text_obj->text);
    if (st_text_obj->font)
        sfFont_destroy(st_text_obj->font);
    if (st_text_obj->str)
        free(st_text_obj->str);
}

void text_obj_destroy(void *text_obj)
{
    text_obj_dtor(text_obj);
    free(text_obj);
}