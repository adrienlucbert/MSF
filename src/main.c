/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "msf/msf.h"

int main(void)
{
    hub_t *hub = hub_new("MSF", vectori_new(1920, 1080), sfDefaultStyle);
    sfEvent evt;

    while (sfRenderWindow_isOpen(hub->window)) {
        while (sfRenderWindow_pollEvent(hub->window, &evt)) {
            if (evt.type == sfEvtClosed) {
                sfRenderWindow_close(hub->window);
            }
        }
    }
    hub_destroy(hub);
    return (0);
}