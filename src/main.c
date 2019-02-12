/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** main
*/

#include "msf/msf.h"
#include "my.h"

int main(int ac, char *av[])
{
    hub_t *hub = hub_new("MSF", vectori_new(1920, 1080), sfDefaultStyle);
    sfEvent evt;

    ac = ac;
    av = av;
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