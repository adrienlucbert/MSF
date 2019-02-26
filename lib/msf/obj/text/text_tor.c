/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** text_tor
*/

#include "msf/msf.h"

void *text_obj_new(char *str, sfColor color, uint char_size)
{
    text_obj_t *st_text_obj = malloc(sizeof(text_obj_t));

    FAIL_IF(!st_text_obj, NULL);
    text_obj_ctor(st_text_obj, str, color, char_size);
    return ((void *)st_text_obj);
}

void text_obj_ctor(void *text_obj, char *str, sfColor color, uint char_size)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    obj_ctor(st_text_obj, text, sfFalse);
    st_text_obj->text = sfText_create();
    st_text_obj->vtable = text_obj_vtable_new();
    st_text_obj->font = NULL;
    st_text_obj->str = NULL;
    text_obj_set_font(st_text_obj, "assets/font/open_sans.ttf");
    text_obj_set_color(st_text_obj, color);
    text_obj_set_char_size(st_text_obj, char_size);
    text_obj_set_string(st_text_obj, str);
    st_text_obj->physics = physics_new(text_obj);
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