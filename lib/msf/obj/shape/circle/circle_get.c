/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_get
*/

#include "msf/msf.h"

float circle_get_radius(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    float radius = 0;

    FAIL_IF(!st_circle || !st_circle->shape, radius);
    radius = sfCircleShape_getRadius(st_circle->shape);
    return (radius);
}

size_t circle_get_point_count(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    size_t point_count = 0;

    FAIL_IF(!st_circle || !st_circle->shape, point_count);
    point_count = sfCircleShape_getPointCount(st_circle->shape);
    return (point_count);
}

sfFloatRect circle_get_box(void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;
    sfVector2f origin = VGET(st_circle, get_origin);
    sfVector2f pos = VGET(st_circle, get_position);
    sfVector2u size = VGET(st_circle, get_size);
    sfVector2f scale = VGET(st_circle, get_scale);
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF(!st_circle, box);
    box.left = pos.x - origin.x;
    box.top = pos.y - origin.x;
    box.width = size.x * scale.x;
    box.height = size.y * scale.y;
    return (box);
}