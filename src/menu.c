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
    shape_obj_t *rect = rect_new((sfVector2u){200, 100}, sfColor_fromRGB(50, 50, 50));
    text_obj_t *text = text_obj_new("Button", sfWhite, 40);
    input_obj_t *box = input_obj_new(rect, text, (sfVector2f){800, 500});

    scene_add_obj(menu, box, "input");
    hub_add_scene(hub, menu, "menu");
}