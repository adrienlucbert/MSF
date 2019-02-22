/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_set
*/

#include "msf/msf.h"

void rect_set_outline_color(void *rect, sfColor outline)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    st_rect->outline_color = outline;
    sfRectangleShape_setOutlineColor(st_rect->shape, outline);
}

void rect_set_fill_color(void *rect, sfColor fill)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    st_rect->fill_color = fill;
    sfRectangleShape_setFillColor(st_rect->shape, fill);
}

void rect_set_outline_thickness(void *rect, float thickness)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    st_rect->outline_thickness = thickness;
    sfRectangleShape_setOutlineThickness(st_rect->shape, thickness);
}

void rect_set_size(void *rect, sfVector2f size)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    sfRectangleShape_setSize(st_rect->shape, size);
}

void rect_set_scale(void *rect, sfVector2f scale)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    sfRectangleShape_setScale(st_rect->shape, scale);
}