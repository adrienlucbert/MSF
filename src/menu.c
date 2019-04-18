/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** menu
*/

#include "project.h"

void window_view_move(hub_t *hub, sfEvent evt)
{
    int nb_move = 0;
    float speed = 10;
    sfBool keys[4] = {KPRESSED(sfKeyUp), KPRESSED(sfKeyDown), \
        KPRESSED(sfKeyLeft), KPRESSED(sfKeyRight)};
    sfInt64 elapsed = sfClock_getElapsedTime(hub->timer).microseconds / 10000;
    sfView *view = sfRenderWindow_getView(hub->window);
    sfVector2f move = VECT2F(0, 0);

    nb_move += keys[0] && !keys[1] ? 1 : 0;
    nb_move += keys[1] && !keys[0] ? 1 : 0;
    nb_move += keys[2] && !keys[3] ? 1 : 0;
    nb_move += keys[3] && !keys[2] ? 1 : 0;
    FAIL_IF_VOID(nb_move == 0);
    speed /= (nb_move > 1) ? sqrt(2) : 1;
    move.y -= keys[0] ? speed * elapsed : 0;
    move.y += keys[1] ? speed * elapsed : 0;
    move.x -= keys[2] ? speed * elapsed : 0;
    move.x += keys[3] ? speed * elapsed : 0;
    sfView_move(view, move);
    sfRenderWindow_setView(hub->window, view);
}

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
    scene_add_evt(menu, evt_new(window_view_move, context), NULL);
    obj_set_z_index(&container->objs, box, -1);
    hub_add_scene(hub, menu, "menu");
}