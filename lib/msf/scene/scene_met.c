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
    node_t *next = NULL;

    FAIL_IF_VOID(!st_scene || !st_scene->objs);
    curr = (node_t *)st_scene->objs;
    next = curr->next;
    while (next != st_scene->objs) {
        obj_render((void *)curr, hub);
        curr = next;
        next = (node_t *)next->next;
    };
    obj_render((void *)curr, hub);
}