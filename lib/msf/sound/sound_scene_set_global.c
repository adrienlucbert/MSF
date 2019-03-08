/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** scene_set
*/

#include "msf/msf.h"

void scene_set_global_volume(void *scene, float volume)
{
    scene_t *st_scene = scene;

    FAIL_IF_VOID(!st_scene || volume < 0.0 || volume > 100.0);
    if (st_scene->sound != NULL)
        sfSound_setVolume(st_scene->sound, volume);
    objs_set_volume(st_scene->objs, volume);
}

void scenes_set_global_volume(void *scene, float volume)
{
    scene_t *st_scenes = scene;
    scene_t *next = st_scenes ? st_scenes->next : NULL;

    FAIL_IF_VOID(!st_scenes || !next || volume < 0.0 || volume > 100.0);
    while (next != st_scenes) {
        if (next->sound != NULL)
            sfSound_setVolume(next->sound, volume);
        objs_set_volume(next->objs, volume);
        next = next->next;
    }
    if (next->sound != NULL)
        sfSound_setVolume(next->sound, volume);
    objs_set_volume(next->objs, volume);
}

void scene_global_sound_apply(scene_t *scene, void (*func)(sfSound *))
{
    scene_sound_apply(scene, func);
    objs_sound_apply(scene->objs, func);
}

void scenes_global_sound_apply(scene_t *scene, void (*func)(sfSound *))
{
    scene_t *buffer = NULL;

    FAIL_IF_VOID(!scene || !func);
    while (list_poll(scene, (void **)&buffer))
        scene_global_sound_apply(buffer, func);
}