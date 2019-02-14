/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** hub_set
*/

#include "msf/msf.h"

void hub_set_framerate(void *hub, uint framerate)
{
    hub_t *st_hub = (hub_t *)hub;

    if (!st_hub)
        return;
    else if (framerate > 0) {
        st_hub->framerate = framerate;
    }
}