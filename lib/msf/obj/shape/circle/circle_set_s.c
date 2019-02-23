/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_set_s
*/

#include "msf/msf.h"

void circle_set_outline_color(void *circle, sfColor outline)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    sfCircleShape_setOutlineColor(st_circle->shape, outline);
}

void circle_set_fill_color(void *circle, sfColor fill)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    sfCircleShape_setFillColor((sfCircleShape *)st_circle->shape, fill);
}

void circle_set_outline_thickness(void *circle, float thickness)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    sfCircleShape_setOutlineThickness(st_circle->shape, thickness);
}

void circle_set_texture(void *circle, sfTexture *texture, sfBool reset)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !st_circle->shape || !texture);
    sfCircleShape_setTexture(st_circle->shape, texture, reset);
}