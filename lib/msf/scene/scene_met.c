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

static append_obj_on_layer(scene_t *st_scene, obj_t *new, int disp_layer)
{
    obj_t *prev = NULL;
    obj_t *curr = st_scene->objs;

    if (curr->disp_layer < disp_layer) {
        while (list_poll(st_scene->objs, (void **)(&prev))) {}
        prev->next = new;
        new->next = curr;
        st_scene->objs = new;
        return;
    }
    while (curr->next != st_scene->objs) {
        if (((obj_t *)curr->next)->disp_layer < disp_layer) {
            curr = curr->next;
            curr->next = new;
            new->next = st_scene->objs;
            return;
        }
    }
}

void scene_add_obj(void *scene, void *obj, char *label, int disp_layer)
{
    scene_t *st_scene = (scene_t *)scene;
    obj_t *new = obj;
    obj_t *prev = NULL;
    obj_t *curr = st_scene->objs;

    FAIL_IF_VOID(!st_scene || !obj);
    node_ctor(obj, label, NULL);
    new->disp_layer = disp_layer;
    if (!st_scene->objs) {
        st_scene->objs = new;
        return;
    }
    append_obj_on_layer(st_scene, new, disp_layer);
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