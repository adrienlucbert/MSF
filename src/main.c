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
    sfEvent evt;

    while (sfRenderWindow_isOpen(hub->window)) {
        sfRenderWindow_clear(hub->window, sfWhite);
        hub_trigger_evts_scope(hub, context, evt);
        while (sfRenderWindow_pollEvent(hub->window, &evt)) {
            hub_trigger_evts_scope(hub, inputs, evt);
        }
        hub_render(hub);
        sfRenderWindow_display(hub->window);
    }
    hub_destroy(hub);
    return (0);
}