/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** hub
*/

#include "msf/msf.h"

void *hub_new(char *title, sfVector2i size, sfUint32 style)
{
    hub_t *st_hub = malloc(sizeof(hub_t));

    FAIL_IF(!st_hub, NULL);
    hub_ctor(st_hub, title, size, style);
    hub_add_global_evt(st_hub, evt_new(window_close_evt, inputs), NULL);
    hub_add_global_evt(st_hub, evt_new(mouse_evt_updater_evt, inputs), NULL);
    return ((void *)st_hub);
}

void hub_ctor(void *hub, char *title, sfVector2i size, sfUint32 style)
{
    hub_t *st_hub = (hub_t *)hub;

    FAIL_IF_VOID(!st_hub);
    title = title;
    size = size;
    style = style;
    st_hub->window = window_new(title, size, style);
    st_hub->global_evts = NULL;
    st_hub->framerate = 60;
    st_hub->timer = sfClock_create();
    st_hub->scenes = NULL;
    st_hub->manifold = manifold_new(NULL, NULL);
}

void hub_dtor(void *hub)
{
    hub_t *st_hub = (hub_t *)hub;

    window_destroy(st_hub->window);
    sfClock_destroy(st_hub->timer);
    list_destroy(st_hub->global_evts);
    list_destroy(st_hub->scenes);
}

void hub_destroy(void *hub)
{
    hub_dtor(hub);
    free(hub);
}