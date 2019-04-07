/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_tor
*/

#include "msf/msf.h"

void *anim_new(hub_t *hub, char *image, int nb_frames)
{
    anim_t *st_anim = malloc(sizeof(anim_t));

    FAIL_IF(!st_anim || !hub || !image, NULL);
    anim_ctor((void *)st_anim, hub, image, nb_frames);
    if (st_anim->frames == NULL) {
        free(st_anim);
        return (NULL);
    }
    return ((void *)st_anim);
}

void anim_ctor(void *anim, hub_t *hub, char *image, int nb_frames)
{
    anim_t *st_anim = (anim_t *)anim;

    FAIL_IF_VOID(!st_anim || !hub || !image);
    st_anim->frame_duration = -1;
    st_anim->frames = NULL;
    st_anim->loop = sfTrue;
    anim_set_frames(anim, hub, image, nb_frames);
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