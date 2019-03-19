/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** window_methods
*/

#include "msf/msf.h"

void window_render(hub_t *hub)
{
    sfInt64 delay = 0;

    FAIL_IF_VOID(!hub || !hub->scenes || !hub->timer);
    delay = sfClock_getElapsedTime(hub->timer).microseconds;
    if (delay >= (1000 / hub->framerate) * 1000) {
        hub_render(hub);
    }
}

void window_clear(hub_t *hub)
{
    sfInt64 delay = 0;

    FAIL_IF_VOID(!hub || !hub->scenes || !hub->timer);
    delay = sfClock_getElapsedTime(hub->timer).microseconds;
    if (delay >= (1000 / hub->framerate) * 1000) {
        sfRenderWindow_clear(hub->window, ((scene_t *)hub->scenes)->clear);
    }
}