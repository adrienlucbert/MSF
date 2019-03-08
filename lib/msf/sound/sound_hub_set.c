/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** sound_hub_set
*/

#include "msf/msf.h"

void hub_set_sound_buffer(hub_t *hub, char *label)
{
    sound_buffer_t *buffer = list_fetch(hub->sound_buffers, label);
    sfSound *sound = NULL;

    FAIL_IF_VOID(!hub || !buffer);
    sound = hub->sound;
    hub->sound = NULL;
    if (sound)
        sfSound_destroy(sound);
    hub->sound = sfSound_create();
    sfSound_setBuffer(hub->sound, buffer->buffer);
}

void hub_set_volume(hub_t *hub, float volume)
{
    FAIL_IF_VOID(!hub || volume < 0.0 || volume > 100.0);
    if (hub->sound != NULL)
        sfSound_setVolume(hub->sound, volume);
}

void hub_set_global_volume(hub_t *hub, float volume)
{
    FAIL_IF_VOID(!hub || volume < 0.0 || volume > 100.0);
    hub_set_volume(hub, volume);
    scenes_set_global_volume(hub->scenes, volume);
}

void hub_sound_apply(hub_t *hub, void (*func)(sfSound *))
{
    FAIL_IF_VOID(!hub || !hub->sound || !func);
    func(hub->sound);
}

void hub_global_sound_apply(hub_t *hub, void (*func)(sfSound *))
{
    FAIL_IF_VOID(!hub || !hub->sound || !func);
    func(hub->sound);
    scenes_global_sound_apply(hub->scenes, func);
}