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
    shape_obj_t *circle = circle_new(50, -1, sfGreen);
    shape_obj_t *rect = rect_new((sfVector2u){1920, 100}, sfBlack);

    VFUNC(rect, set_position, (sfVector2f){0, 920});
    VFUNC(circle, set_position, (sfVector2f){930, 0});
    rect->physics->mass = 0;
    rect->physics->inv_mass = 0;
    obj_physics_set_gravity(circle, 0.5);
    obj_physics_set_restitution(circle, 0.5);

    scene_add_obj(menu, rect, "floor");
    scene_add_obj(menu, circle, "ball1");
    hub_add_scene(hub, menu, "menu");
}