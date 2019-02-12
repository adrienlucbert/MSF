/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** global_evts
*/

#include "msf/msf.h"

void window_close_evt(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(hub->window);
}