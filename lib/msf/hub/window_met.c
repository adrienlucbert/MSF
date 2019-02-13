/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** window_methods
*/

#include "msf/msf.h"

void window_render(hub_t *hub)
{
    sfInt64 delay = sfClock_getElapsedTime(hub->timer).microseconds;

    if (hub->scenes == NULL)
        return;
    if (delay / 1000 >= 1000 / hub->framerate) {
        // scene_refresh(hub);
        sfClock_restart(hub->timer);
    }
}