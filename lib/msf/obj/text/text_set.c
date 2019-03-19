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
    sfVector2f scale;
    uint size = 0;
    sfColor color = sfBlack;

    FAIL_IF_VOID(!st_text_obj || !fontpath);
    scale = sfText_getScale(st_text_obj->text);
    color = sfText_getColor(st_text_obj->text);
    size = sfText_getCharacterSize(st_text_obj->text);
    if (st_text_obj->text)
        sfText_destroy(st_text_obj->text);
    if (st_text_obj->font)
        sfFont_destroy(st_text_obj->font);
    st_text_obj->text = sfText_create();
    st_text_obj->font = sfFont_createFromFile(fontpath);
    sfText_setFont(st_text_obj->text, st_text_obj->font);
    sfText_setCharacterSize(st_text_obj->text, size);
    sfText_setColor(st_text_obj->text, color);
    sfText_setScale(st_text_obj->text, scale);
    if (st_text_obj->str)
        sfText_setString(st_text_obj->text, st_text_obj->str);
}

void text_obj_set_color(void *text_obj, sfColor color)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setColor(st_text_obj->text, color);
}

void text_obj_set_char_size(void *text_obj, uint char_size)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj || char_size <= 0);
    sfText_setCharacterSize(st_text_obj->text, char_size);
}

void text_obj_set_string(void *text_obj, char *str)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    if (st_text_obj) {
        if (st_text_obj->str)
            free(st_text_obj->str);
        st_text_obj->str = my_memdup(str, -1);
        sfText_setString(st_text_obj->text, str);
    }
}