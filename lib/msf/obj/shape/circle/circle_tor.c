/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** circle_tor
*/

#include "msf/msf.h"

void *circle_new(float radius, size_t point_count, sfColor color)
{
    shape_obj_t *st_circle = malloc(sizeof(shape_obj_t));

    FAIL_IF(!st_circle, NULL);
    circle_ctor(st_circle, radius, point_count, color);
    return ((void *)st_circle);
}

void circle_ctor(void *circle, float radius, size_t point_count, sfColor color)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle);
    obj_ctor(st_circle, shape);
    circle_set_outline_color(st_circle, color);
    circle_set_fill_color(st_circle, color);
    circle_set_radius(st_circle, radius);
    circle_set_point_count(st_circle, point_count);
    st_circle->render = circle_render;
    st_circle->dtor = circle_dtor;
}

void circle_dtor(void *shape_obj)
{
    shape_obj_t *st_circle = (shape_obj_t *)shape_obj;

    obj_dtor(shape_obj);
    sfCircleShape_destroy((sfCircleShape *)st_circle->shape);
}

void circle_destroy(void *shape_obj)
{
    circle_dtor(shape_obj);
    free(shape_obj);
}