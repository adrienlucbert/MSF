/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_get_t
*/

#include "msf/msf.h"

sfVector2f circle_get_origin(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_circle || !st_circle->shape, origin);
    origin = sfCircleShape_getOrigin(st_circle->shape);
    return (origin);
}

sfVector2f circle_get_position(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfVector2f position = {0, 0};

    FAIL_IF(!st_circle || !st_circle->shape, position);
    position = sfCircleShape_getPosition(st_circle->shape);
    return (position);
}

float circle_get_rotation(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    float rotation = 0;

    FAIL_IF(!st_circle || !st_circle->shape, rotation);
    rotation = sfCircleShape_getRotation(st_circle->shape);
    return (rotation);
}

sfVector2f circle_get_scale(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfVector2f scale = {0, 0};

    FAIL_IF(!st_circle || !st_circle->shape, scale);
    scale = sfCircleShape_getScale(st_circle->shape);
    return (scale);
}

sfVector2u circle_get_size(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfFloatRect bounds;
    sfVector2u size = {0, 0};

    FAIL_IF(!st_circle || !st_circle->shape, size);
    bounds = sfCircleShape_getGlobalBounds(st_circle->shape);
    size.x = bounds.width;
    size.y = bounds.height;
    return (size);
}