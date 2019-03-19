/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_get
*/

#include "msf/msf.h"

sfSoundStatus sound_obj_get_status(void *sound)
{
    sound_obj_t *st_sound = sound;

    FAIL_IF(!st_sound, 0);
    return (sfSound_getStatus(st_sound->sound));
}

sfBool sound_obj_get_loop(void *sound)
{
    sound_obj_t *st_sound = sound;

    FAIL_IF(!st_sound, sfFalse);
    return (sfSound_getLoop(st_sound->sound));
}