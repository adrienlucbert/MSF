/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** text_set
*/

#include "msf/msf.h"

void text_obj_set_font(void *text_obj, char *fontpath)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    st_text_obj->font = NULL;
    if (fontpath) {
        st_text_obj->font = sfFont_createFromFile(fontpath);
    }
    sfText_setFont(st_text_obj->text, st_text_obj->font);
}

void text_obj_set_color(void *text_obj, sfColor color)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    st_text_obj->color = color;
    sfText_setColor(st_text_obj->text, st_text_obj->color);
}

void text_obj_set_char_size(void *text_obj, uint char_size)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj || char_size <= 0);
    st_text_obj->char_size = char_size;
    sfText_setCharacterSize(st_text_obj->text, st_text_obj->char_size);
}

void text_obj_set_string(void *text_obj, char *str)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    if (st_text_obj) {
        if (st_text_obj->str != NULL)
            free(st_text_obj->str);
        if (str != NULL)
            st_text_obj->str = my_memdup(str, -1);
        else
            st_text_obj->str = NULL;
        sfText_setString(st_text_obj->text, st_text_obj->str);
    }
}