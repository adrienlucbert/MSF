/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_set
*/

#include "msf/msf.h"

void circle_set_radius(void *circle, float radius)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle);
    sfCircleShape_setRadius(st_circle->shape, radius);
}

void circle_set_point_count(void *circle, int point_count)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || point_count < 0);
    sfCircleShape_setPointCount(st_circle->shape, point_count);
}