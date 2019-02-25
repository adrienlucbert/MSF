/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "project.h"

int main(void)
{
    hub_t *hub = hub_new("MSF", (sfVector2i){1920, 1080}, sfDefaultStyle);
    menu_create(hub);
    scene_t *menu = hub->scenes;
    shape_obj_t *first_circle = list_fetch(menu->objs, "ball1");
    shape_obj_t *circle = NULL;
    sfEvent evt;
    sfVector2f mouse_pos = {0, 0};

    while (sfRenderWindow_isOpen(hub->window)) {
        hub_trigger_evts_scope(hub, context, evt);
        while (sfRenderWindow_pollEvent(hub->window, &evt)) {
            hub_trigger_evts_scope(hub, inputs, evt);
            if (evt.type == sfEvtMouseButtonPressed) {
                mouse_pos.x = evt.mouseButton.x;
                circle = circle_new(50, -1, sfGreen);
                VFUNC(circle, set_position, mouse_pos);
                obj_physics_set_gravity(circle, 0.5);
                obj_physics_set_restitution(circle, 0.5);
                scene_add_obj(menu, circle, "ball");
            }
            if (evt.type == sfEvtKeyPressed) {
                sfRenderWindow_clear(hub->window, sfWhite);
                window_render(hub);
                printf("% 5.2f % 5.2f\n", first_circle->physics->speed.x, first_circle->physics->speed.y);
            }
            // if (evt.type == sfEvtMouseMoved) {
            //     VFUNC(floor, set_position, mouse_pos);
            // }
        }
        // hub_render(hub);
        sfRenderWindow_display(hub->window);
    }
    hub_destroy(hub);
    return (0);
}