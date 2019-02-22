/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** circle_met
*/

#include "msf/msf.h"

void circle_render(hub_t *hub, void *circle)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !hub);
    sfCircleShape_setPosition(st_circle->shape, st_circle->pos);
    sfRenderWindow_drawCircleShape(hub->window, st_circle->shape, NULL);
}