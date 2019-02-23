/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_get_s
*/

#include "msf/msf.h"

sfColor rect_get_outline_color(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfColor color = sfWhite;

    FAIL_IF(!st_rect || !st_rect->shape, color);
    color = sfRectangleShape_getOutlineColor(st_rect->shape);
    return (color);
}

sfColor rect_get_fill_color(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfColor color = sfWhite;

    FAIL_IF(!st_rect || !st_rect->shape, color);
    color = sfRectangleShape_getFillColor((sfRectangleShape *)st_rect->shape);
    return (color);
}

float rect_get_outline_thickness(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    float thickness = 0;

    FAIL_IF(!st_rect || !st_rect->shape, thickness);
    thickness = sfRectangleShape_getOutlineThickness(st_rect->shape);
    return (thickness);
}

const sfTexture *rect_get_texture(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    const sfTexture *texture = NULL;

    FAIL_IF(!st_rect || !st_rect->shape, texture);
    texture = sfRectangleShape_getTexture(st_rect->shape);
    return (texture);
}