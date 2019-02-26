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
    shape_obj_t *rect = rect_new((sfVector2u){60, 10}, sfWhite);
    text_obj_t *text = text_obj_new("Test", sfRed, 80);
    input_obj_t *box = input_obj_new(rect, text, (sfVector2f){200, 800});
    input_obj_recenter(box);

    scene_add_obj(menu, box, "input");
    hub_add_scene(hub, menu, "menu");
}