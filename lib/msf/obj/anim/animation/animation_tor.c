/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_tor
*/

#include "msf/msf.h"

void *anim_new(char *filepath, int nb_frames, uint frame_duration)
{
    anim_t *st_anim = malloc(sizeof(anim_t));

    FAIL_IF(!st_anim, NULL);
    anim_ctor((void *)st_anim, filepath, nb_frames, frame_duration);
    return ((void *)st_anim);
}

void anim_ctor(void *anim, char *filepath, int nb_frames, uint frame_duration)
{
    anim_t *st_anim = (anim_t *)anim;

    FAIL_IF_VOID(!st_anim);
    st_anim->frame_duration = frame_duration;
    st_anim->frames = NULL;
    anim_set_frames(anim, filepath, nb_frames);
    st_anim->dtor = anim_dtor;
}

void anim_dtor(void *anim)
{
    anim_t *st_anim = (anim_t *)anim;

    list_destroy(st_anim->frames);
}

void anim_destroy(void *anim)
{
    anim_dtor(anim);
    free(anim);
}