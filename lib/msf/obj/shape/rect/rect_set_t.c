/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_set_t
*/

#include "msf/msf.h"

void rect_set_origin(void *rect, sfVector2f origin)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setOrigin(st_rect->shape, origin);
}

void rect_set_position(void *rect, sfVector2f position)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setPosition(st_rect->shape, position);
}

void rect_set_rotation(void *rect, float rotation)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setRotation(st_rect->shape, rotation);
}

void rect_set_scale(void *rect, sfVector2f scale)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setScale(st_rect->shape, scale);
}

void rect_set_size(void *rect, sfVector2u size)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    sfRectangleShape_setSize(st_rect->shape, (sfVector2f){size.x, size.y});
}