/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** text_get_s
*/

#include "msf/msf.h"

sfColor text_obj_get_fill_color(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    sfColor color = sfWhite;

    FAIL_IF(!st_text_obj || !st_text_obj->text, color);
    color = sfText_getFillColor(st_text_obj->text);
    return (color);
}

sfColor text_obj_get_outline_color(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    sfColor color = sfWhite;

    FAIL_IF(!st_text_obj || !st_text_obj->text, color);
    color = sfText_getOutlineColor(st_text_obj->text);
    return (color);
}

float text_obj_get_outline_thickness(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    float thickness = 0;

    FAIL_IF(!st_text_obj || !st_text_obj->text, thickness);
    thickness = sfText_getOutlineThickness(st_text_obj->text);
    return (thickness);
}