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
    anim_obj_t *cowboi = anim_obj_new();
    anim_t *running = anim_new("assets/img/running.png", 10, 70);
    shape_obj_t *circle = circle_new(50, -1, sfGreen);
    shape_obj_t *rect = rect_new((sfVector2f){50, 10}, sfRed);

    anim_obj_add_anim(cowboi, running, "running");
    scene_add_obj(menu, cowboi, "cowboi");
    scene_add_obj(menu, rect, "rect");
    scene_add_obj(menu, circle, "circle");
    hub_add_scene(hub, menu, "menu");
}