/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "msf/msf.h"

int main(void)
{
    hub_t *hub = hub_new("MSF", (sfVector2i){1920, 1080}, sfDefaultStyle);
    sfEvent evt;

    while (sfRenderWindow_isOpen(hub->window)) {
        sfRenderWindow_clear(hub->window, sfWhite);
        while (sfRenderWindow_pollEvent(hub->window, &evt)) {
            if (evt.type == sfEvtClosed) {
                sfRenderWindow_close(hub->window);
            }
        }
        sfRenderWindow_display(hub->window);
    }
    hub_destroy(hub);
    return (0);
}