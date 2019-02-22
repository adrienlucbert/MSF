/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** rect_met
*/

#include "msf/msf.h"

void rect_render(void *shape_obj, hub_t *hub)
{
    shape_obj_t *st_shape_obj = (shape_obj_t *)shape_obj;

    FAIL_IF_VOID(!st_shape_obj || !hub);
    sfRectangleShape_setPosition(st_shape_obj->shape, st_shape_obj->pos);
    sfRenderWindow_drawRectangleShape(hub->window, st_shape_obj->shape, NULL);
}