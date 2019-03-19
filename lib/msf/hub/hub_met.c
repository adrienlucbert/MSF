/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** hub_met
*/

#include "msf/msf.h"

void hub_add_global_evt(void *hub, void *global_evt, char *label)
{
    hub_t *st_hub = (hub_t *)hub;

    FAIL_IF_VOID(!st_hub || !global_evt);
    node_ctor(global_evt, label, NULL);
    list_append(&st_hub->global_evts, global_evt);
}

void hub_add_scene(void *hub, void *scene, char *label)
{
    hub_t *st_hub = (hub_t *)hub;

    FAIL_IF_VOID(!st_hub || !scene);
    node_ctor(scene, label, NULL);
    list_append((void **)&st_hub->scenes, scene);
}

void hub_render(hub_t *hub)
{
    FAIL_IF_VOID(!hub || !hub->scenes);
    scene_render(hub, hub->scenes);
    srand(sfClock_getElapsedTime(hub->timer).microseconds);
    sfClock_restart(hub->timer);
}

void hub_trigger_evts_scope(hub_t *hub, evt_scope scope, sfEvent data)
{
    scene_t *st_scene = NULL;

    FAIL_IF_VOID(!hub || !hub->global_evts);
    evt_trigger_scope(hub->global_evts, scope, hub, data);
    st_scene = (scene_t *)hub->scenes;
    FAIL_IF_VOID(!st_scene || !st_scene->evts);
    evt_trigger_scope(st_scene->evts, scope, hub, data);
}

void hub_add_buffer(void *hub, void *buffer, char *label)
{
    hub_t *st_hub = (hub_t *)hub;

    FAIL_IF_VOID(!st_hub || !buffer);
    node_ctor(buffer, label, NULL);
    list_append((void *)(&st_hub->sound_buffers), buffer);
}