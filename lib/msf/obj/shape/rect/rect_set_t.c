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
    st_rect->physics->pos = position;
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
    sfVector2u actual_size;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    actual_size = rect_get_size(rect);
    st_rect->physics->size.x = actual_size.x * scale.x;
    st_rect->physics->size.y = actual_size.y * scale.y;
    sfRectangleShape_setScale(st_rect->shape, scale);
}

void rect_set_size(void *rect, sfVector2u size)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f actual_scale;

    FAIL_IF_VOID(!st_rect || !st_rect->shape);
    actual_scale = rect_get_scale(rect);
    st_rect->physics->size.x = size.x * actual_scale.x;
    st_rect->physics->size.y = size.y * actual_scale.y;
    sfRectangleShape_setSize(st_rect->shape, VECT2F(size.x, size.y));
}