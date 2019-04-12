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

static void append_obj_on_layer(scene_t *st_scene, obj_t *new, int z_index)
{
    obj_t *prev = NULL;
    obj_t *curr = st_scene->objs;
    int check = 1;

    if (curr->z_index < z_index) {
        while (list_poll(st_scene->objs, (void **)(&prev))) {}
        prev->next = new;
        new->next = curr;
        st_scene->objs = new;
        return;
    }
    while (curr->next != st_scene->objs && check) {
        check = ((obj_t *)curr->next)->z_index < z_index ? 0 : 1;
        curr = ((obj_t *)curr->next)->z_index < z_index ? curr : curr->next;
    }
    prev = curr;
    curr = curr->next;
    prev->next = new;
    new->next = curr;
}

void scene_add_obj(void *scene, void *obj, char *label, int z_index)
{
    scene_t *st_scene = (scene_t *)scene;
    obj_t *new = obj;

    FAIL_IF_VOID(!st_scene || !obj);
    node_ctor(obj, label, NULL);
    new->z_index = z_index;
    if (!st_scene->objs) {
        st_scene->objs = new;
        return;
    }
    append_obj_on_layer(st_scene, new, z_index);
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