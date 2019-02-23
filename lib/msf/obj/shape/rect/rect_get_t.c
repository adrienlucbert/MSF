/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_get_t
*/

#include "msf/msf.h"

sfVector2f rect_get_origin(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, origin);
    origin = sfRectangleShape_getOrigin(st_rect->shape);
    return (origin);
}

sfVector2f rect_get_position(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f position = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, position);
    position = sfRectangleShape_getPosition(st_rect->shape);
    return (position);
}

float rect_get_rotation(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    float rotation = 0;

    FAIL_IF(!st_rect || !st_rect->shape, rotation);
    rotation = sfRectangleShape_getRotation(st_rect->shape);
    return (rotation);
}

sfVector2f rect_get_scale(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f scale = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, scale);
    scale = sfRectangleShape_getScale(st_rect->shape);
    return (scale);
}

sfVector2u rect_get_size(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfFloatRect bounds;
    sfVector2u size = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, size);
    bounds = sfRectangleShape_getGlobalBounds(st_rect->shape);
    size.x = bounds.width;
    size.y = bounds.height;
    return (size);
}