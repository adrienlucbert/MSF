/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "project.h"

void menu_create(hub_t *hub)
{
    scene_t *menu = scene_new();
    shape_obj_t *circle = circle_new(200, 3, sfGreen);
    shape_obj_t *rectangle = rect_new((sfVector2f){40, 70}, sfRed);

    rectangle->pos = (sfVector2f){300, 400};
    circle->pos = (sfVector2f){300, 400};
    circle_set_outline_thickness(circle, -10);
    circle_set_outline_color(circle, sfBlack);
    sfRectangleShape_rotate(rectangle->shape, 45);
    scene_add_obj(menu, circle, "circle");
    scene_add_obj(menu, rectangle, "rect");
    hub_add_scene(hub, menu, "menu");
}