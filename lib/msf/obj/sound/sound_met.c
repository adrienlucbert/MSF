/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** rect_met
*/

#include "msf/msf.h"

void sound_obj_render(void *sound, hub_t *hub)
{
    sound_obj_t *st_sound = sound;
    sfInt64 elapsed_ms = 0;

    FAIL_IF_VOID(!hub);
    elapsed_ms = sfClock_getElapsedTime(hub->timer).microseconds / 1000;
    FAIL_IF_VOID(!st_sound || !st_sound->sound || !st_sound->loop);
    elapsed_ms += st_sound->elapsed;
    FAIL_IF_VOID(sfSound_getLoop(st_sound->sound))
    if (sound_obj_get_status(st_sound) != sfPlaying) {
        if (elapsed_ms > st_sound->repeat_delay)
            sfSound_play(st_sound->sound);
    }
}