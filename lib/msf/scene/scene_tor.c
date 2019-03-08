/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** scene_tor
*/

#include "msf/msf.h"

void *scene_new(void)
{
    scene_t *st_scene = malloc(sizeof(scene_t));

    FAIL_IF(!st_scene, NULL);
    scene_ctor(st_scene);
    return ((void *)st_scene);
}

void scene_ctor(void *scene)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene);
    st_scene->objs = NULL;
    st_scene->evts = NULL;
    st_scene->sound = NULL;
    st_scene->clear = sfBlack;
    st_scene->cam_pos = VECT2F(0, 0);
    st_scene->cam_speed = VECT2F(0, 0);
    st_scene->dtor = scene_dtor;
}

void scene_dtor(void *scene)
{
    scene_t *st_scene = (scene_t *)scene;

    list_destroy(st_scene->objs);
    list_destroy(st_scene->evts);
    if (st_scene->sound) {
        sfSound_stop(st_scene->sound);
        sfSound_destroy(st_scene->sound);
    }
}

void scene_destroy(void *scene)
{
    scene_dtor(scene);
    free(scene);
}