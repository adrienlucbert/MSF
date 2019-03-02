/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** sound_tor
*/

#include "msf/msf.h"

void *sound_buffer_new(char *path)
{
    sound_buffer_t *st_sound_buffer = malloc(sizeof(*st_sound_buffer));

    FAIL_IF(!st_sound_buffer, NULL);
    sound_buffer_ctor(st_sound_buffer, path);
    return ((void *)st_sound_buffer);
}

void sound_buffer_ctor(void *sound_buffer, char *path)
{
    sound_buffer_t *st_sound_buffer = (sound_buffer_t *)sound_buffer;

    FAIL_IF_VOID(!st_sound_buffer);
    st_sound_buffer->buffer = sfSoundBuffer_createFromFile(path);
    st_sound_buffer->label = NULL;
    st_sound_buffer->next = NULL;
    st_sound_buffer->dtor = sound_buffer_dtor;
}

void sound_buffer_dtor(void *sound_buffer)
{
    sound_buffer_t *st_sound_buffer = (sound_buffer_t *)sound_buffer;

    sfSoundBuffer_destroy(st_sound_buffer->buffer);
}

void sound_buffer_destroy(void *sound_buffer)
{
    sound_buffer_dtor(sound_buffer);
    free(sound_buffer);
}