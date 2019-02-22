/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** rect_tor
*/

#include "msf/msf.h"

void *rect_new(sfVector2f size, sfColor color)
{
    shape_obj_t *st_rect = malloc(sizeof(shape_obj_t));

    FAIL_IF(!st_rect, NULL);
    rect_ctor(st_rect, size, color);
    return ((void *)st_rect);
}

void rect_ctor(void *rect, sfVector2f size, sfColor color)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect);
    obj_ctor(st_rect, shape);
    st_rect->shape = sfRectangleShape_create();
    rect_set_fill_color(st_rect, color);
    rect_set_outline_color(st_rect, color);
    rect_set_size(st_rect, size.x, size.y);
    st_rect->render = rect_render;
    st_rect->dtor = rect_dtor;
}

void rect_dtor(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    obj_dtor(st_rect);
    sfRectangleShape_destroy(st_rect->shape);
}

void rect_destroy(void *shape_obj)
{
    rect_dtor(shape_obj);
    free(shape_obj);
}