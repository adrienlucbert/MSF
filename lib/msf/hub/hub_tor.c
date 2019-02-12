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
    return ((void *)st_hub);
}

void *hub_ctor(void *hub, char *title, sfVector2i size, sfUint32 style)
{
    hub_t *st_hub = (hub_t *)hub;

    FAIL_IF(!st_hub, NULL);
    title = title;
    size = size;
    style = style;
    st_hub->window = window_new(title, size, style);
    st_hub->global_evt = NULL;
    st_hub->framerate = 60;
    st_hub->timer = sfClock_create();
    st_hub->scene = NULL;
    return (hub);
}

void hub_dtor(void *hub)
{
    hub_t *st_hub = (hub_t *)hub;

    window_destroy(st_hub->window);
    sfClock_destroy(st_hub->timer);
    list_destroy(st_hub->global_evt);
    list_destroy(st_hub->scene);
}

void hub_destroy(void *hub)
{
    hub_dtor(hub);
    free(hub);
}