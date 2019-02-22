/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "project.h"
#include <stdio.h>

void menu_create(hub_t *hub)
{
    scene_t *menu = scene_new();
    anim_obj_t *cowboi = anim_obj_new();
    anim_t *running = anim_new("assets/img/running.png", 10, 70);

    anim_obj_add_anim(cowboi, running, "running");
    scene_add_obj(menu, cowboi, "cowboi");
    hub_add_scene(hub, menu, "menu");
}