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