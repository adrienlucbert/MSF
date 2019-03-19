/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_set_s
*/

#include "msf/msf.h"

void sound_obj_set_loop(void *sound, sfBool loop, sfInt64 delay)
{
    sound_obj_t *st_sound = sound;

    FAIL_IF_VOID(!st_sound || !st_sound->sound);
    st_sound->loop = loop;
    sfSound_setLoop(st_sound->sound, !loop);
    st_sound->repeat_delay = delay;
}