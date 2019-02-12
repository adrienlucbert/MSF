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

    node_ctor(evt, label, NULL);
    list_append(st_scene->evts, evt);
}

void scene_add_obj(void *scene, void *obj, char *label)
{
    scene_t *st_scene = (scene_t *)scene;

    node_ctor(obj, label, NULL);
    list_append(st_scene->objs, obj);
}