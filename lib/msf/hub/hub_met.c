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
    list_append(&st_hub->scenes, scene);
}