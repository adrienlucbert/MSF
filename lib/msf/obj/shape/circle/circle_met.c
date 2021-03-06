/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** circle_met
*/

#include "msf/msf.h"

void circle_render(void *circle, hub_t *hub)
{
    shape_obj_t *st_circle = (shape_obj_t *)circle;

    FAIL_IF_VOID(!st_circle || !hub);
    sfRenderWindow_drawCircleShape(hub->window, st_circle->shape, NULL);
}