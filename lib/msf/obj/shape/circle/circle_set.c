/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_set
*/

#include "msf/msf.h"

void circle_set_outline_color(void *circle, sfColor outline)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle);
    st_circle->outline_color = outline;
    sfCircleShape_setOutlineColor(st_circle->shape, outline);
}

void circle_set_fill_color(void *circle, sfColor fill)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle);
    st_circle->fill_color = fill;
    sfCircleShape_setFillColor((sfCircleShape *)st_circle->shape, fill);
}

void circle_set_outline_thickness(void *circle, float thickness)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle);
    st_circle->outline_thickness = thickness;
    sfCircleShape_setOutlineThickness(st_circle->shape, thickness);
}

void circle_set_radius(void *circle, float radius)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle);
    st_circle->radius = radius;
    sfCircleShape_setRadius(st_circle->shape, radius);
}

void circle_set_point_count(void *circle, int point_count)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || point_count < 0);
    st_circle->point_count = point_count;
    sfCircleShape_setPointCount(st_circle->shape, point_count);
}