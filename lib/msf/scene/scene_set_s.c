/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** scene_set
*/

#include "msf/msf.h"

void scene_set_sound_buffer(hub_t *hub, void *scene, char *label)
{
    scene_t *st_scene = scene;
    sound_buffer_t *buffer = list_fetch(hub->sound_buffers, label);
    sfSound *sound = NULL;

    FAIL_IF_VOID(!st_scene || !buffer);
    sound = st_scene->sound;
    st_scene->sound = NULL;
    if (sound)
        sfSound_destroy(sound);
    st_scene->sound = sfSound_create();
    sfSound_setBuffer(st_scene->sound, buffer->buffer);
}

void scene_set_volume(void *scene, float volume)
{
    scene_t *st_scene = scene;

    FAIL_IF_VOID(!st_scene || volume < 0.0 || volume > 100.0);
    if (st_scene->sound != NULL)
        sfSound_setVolume(st_scene->sound, volume);
}

void scenes_set_volume(void *scene, float volume)
{
    scene_t *st_scenes = scene;
    scene_t *next = st_scenes ? st_scenes->next : NULL;

    FAIL_IF_VOID(!st_scenes || !next || volume < 0.0 || volume > 100.0);
    while (next != st_scenes) {
        if (next->sound != NULL)
            sfSound_setVolume(next->sound, volume);
        next = next->next;
    }
    if (next->sound != NULL)
        sfSound_setVolume(next->sound, volume);
}

void scene_sound_apply(scene_t *scene, void (*func)(sfSound *))
{
    FAIL_IF_VOID(!scene || !func || !scene->sound);
    func(scene->sound);
}

void scenes_sound_apply(scene_t *scene, void (*func)(sfSound *))
{
    scene_t *buffer = NULL;

    FAIL_IF_VOID(!scene || !func);
    while (list_poll(scene, (void **)&buffer))
        scene_sound_apply(buffer, func);
}