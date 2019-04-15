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
    obj_container_t *container = obj_container_new();
    shape_obj_t *rect = rect_new((sfVector2u){200, 100}, RGBA(50, 50, 50, 255));
    text_obj_t *text = text_obj_new("Button", sfWhite, 40);
    input_obj_t *box = input_obj_new(rect, text, (sfVector2f){800, 500});
    shape_obj_t *test = rect_new((sfVector2u){200, 120}, sfGreen);
    shape_obj_t *test2 = rect_new((sfVector2u){220, 100}, sfRed);

    rect_set_position(test, VECT2F(800, 510));
    rect_set_position(test2, VECT2F(810, 500));
    obj_container_add_obj(container, box, "input", 2);
    obj_container_add_obj(container, test2, "red", 0);
    obj_container_add_obj(container, test, "green", 1);
    scene_add_obj(menu, container, "container", 0);
    obj_set_z_index(&container->objs, box, -1);
    hub_add_scene(hub, menu, "menu");
}