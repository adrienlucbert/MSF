/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_get_s
*/

#include "msf/msf.h"

sfColor circle_get_outline_color(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfColor color = sfWhite;

    FAIL_IF(!st_circle || !st_circle->shape, color);
    color = sfCircleShape_getOutlineColor(st_circle->shape);
    return (color);
}

sfColor circle_get_fill_color(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfColor color = sfWhite;

    FAIL_IF(!st_circle || !st_circle->shape, color);
    color = sfCircleShape_getFillColor((sfCircleShape *)st_circle->shape);
    return (color);
}

float circle_get_outline_thickness(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    float thickness = 0;

    FAIL_IF(!st_circle || !st_circle->shape, thickness);
    thickness = sfCircleShape_getOutlineThickness(st_circle->shape);
    return (thickness);
}

const sfTexture *circle_get_texture(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    const sfTexture *texture = NULL;

    FAIL_IF(!st_circle || !st_circle->shape, texture);
    texture = sfCircleShape_getTexture(st_circle->shape);
    return (texture);
}