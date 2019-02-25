/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_set_t
*/

#include "msf/msf.h"

void circle_set_origin(void *circle, sfVector2f origin)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    sfCircleShape_setOrigin(st_circle->shape, origin);
}

void circle_set_position(void *circle, sfVector2f position)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    float radius = 0;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    radius = st_circle->physics->radius;
    st_circle->physics->pos.x = position.x + radius;
    st_circle->physics->pos.y = position.y + radius;
    sfCircleShape_setPosition(st_circle->shape, position);
}

void circle_set_rotation(void *circle, float rotation)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    sfCircleShape_setRotation(st_circle->shape, rotation);
}

void circle_set_scale(void *circle, sfVector2f scale)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    sfCircleShape_setScale(st_circle->shape, scale);
}

void circle_set_size(void *circle, sfVector2u size)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfVector2f actual_scale;
    sfVector2u actual_size;
    sfVector2f new_scale;

    FAIL_IF_VOID(!st_circle || !st_circle->shape);
    actual_scale = circle_get_scale(circle);
    actual_size = circle_get_size(circle);
    FAIL_IF_VOID(actual_size.x == 0 || actual_size.y == 0);
    new_scale.x = size.x * actual_scale.x / actual_size.x;
    new_scale.y = size.y * actual_scale.y / actual_size.y;
    st_circle->physics->size.x = actual_size.x * new_scale.x;
    st_circle->physics->size.y = actual_size.y * new_scale.y;
    circle_set_scale(circle, new_scale);
}