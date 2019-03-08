/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** scene_met
*/

#include "msf/msf.h"

void scene_add_evt(void *scene, void *evt, char *label)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene || !evt);
    node_ctor(evt, label, NULL);
    list_append(&st_scene->evts, evt);
}

void scene_add_obj(void *scene, void *obj, char *label)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene || !obj);
    node_ctor(obj, label, NULL);
    list_append(&st_scene->objs, obj);
}

void scene_add_buffer(void *scene, void *buffer, char *label)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene || !buffer);
    node_ctor(buffer, label, NULL);
}

void scene_render(hub_t *hub, void *scene)
{
    scene_t *st_scene = (scene_t *)scene;
    node_t *curr = NULL;

    FAIL_IF_VOID(!st_scene || !st_scene->objs);
    while (list_poll(st_scene->objs, (void **)&curr)) {
        obj_render(curr, hub);
    }
}