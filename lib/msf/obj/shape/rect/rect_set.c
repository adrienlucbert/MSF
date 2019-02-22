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

void rect_set_size(void *rect, float x, float y)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    st_rect->size = (sfVector2f){x, y};
    sfRectangleShape_setSize(st_rect->shape, st_rect->size);
}

void rect_set_scale(void *rect, float scale_x, float scale_y)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    st_rect->size.x *= scale_x;
    st_rect->size.y *= scale_y;
    sfRectangleShape_setSize(st_rect->shape, st_rect->size);
}