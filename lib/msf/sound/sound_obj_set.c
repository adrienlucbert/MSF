/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** sound_obj_set
*/

#include "msf/msf.h"

void obj_set_sound_buffer(hub_t *hub, void *obj, char *label)
{
    obj_t *st_obj = obj;
    sound_buffer_t *buffer = list_fetch(hub->sound_buffers, label);
    sfSound *sound = NULL;

    FAIL_IF_VOID(!st_obj || !buffer);
    sound = st_obj->sound;
    st_obj->sound = NULL;
    if (sound)
        sfSound_destroy(sound);
    st_obj->sound = sfSound_create();
    sfSound_setBuffer(st_obj->sound, buffer->buffer);
}

void obj_set_volume(void *obj, float volume)
{
    obj_t *st_obj = obj;

    FAIL_IF_VOID(!st_obj || volume < 0.0 || volume > 100.0);
    if (st_obj->sound != NULL)
        sfSound_setVolume(st_obj->sound, volume);
}

void objs_set_volume(void *obj, float volume)
{
    obj_t *st_obj = obj;
    obj_t *next = st_obj ? st_obj->next : NULL;

    FAIL_IF_VOID(!st_obj || !next || volume < 0.0 || volume > 100.0);
    while (next != st_obj) {
        obj_set_volume(next, volume);
        next = next->next;
    }
    obj_set_volume(next, volume);
}