/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** text_set_s
*/

#include "msf/msf.h"

void text_obj_set_fill_color(void *text_obj, sfColor color)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setFillColor(st_text_obj->text, color);
}

void text_obj_set_outline_color(void *text_obj, sfColor color)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setOutlineColor(st_text_obj->text, color);
}

void text_obj_set_outline_thickness(void *text_obj, float thickness)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setOutlineThickness(st_text_obj->text, thickness);
}