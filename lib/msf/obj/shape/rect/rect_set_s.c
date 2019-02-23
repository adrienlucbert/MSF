/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_set_s
*/

#include "msf/msf.h"

void rect_set_outline_color(void *rect, sfColor outline)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setOutlineColor(st_rect->shape, outline);
}

void rect_set_fill_color(void *rect, sfColor fill)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setFillColor(st_rect->shape, fill);
}

void rect_set_outline_thickness(void *rect, float thickness)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setOutlineThickness(st_rect->shape, thickness);
}

void rect_set_texture(void *rect, sfTexture *texture, sfBool reset)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape || !texture);
    sfRectangleShape_setTexture(st_rect->shape, texture, reset);
}