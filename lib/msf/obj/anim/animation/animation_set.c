/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_set
*/

#include "msf/msf.h"
#include <stdio.h>

void anim_set_frames(void *anim, char *filepath, int nb_frames)
{
    sfImage *sheet = sfImage_createFromFile(filepath);
    sfVector2u size = sfImage_getSize(sheet);
    sfIntRect area = {0, 0, size.x / nb_frames, size.y};
    sfTexture *texture = NULL;
    int frame_id = 0;

    while (frame_id < nb_frames) {
        texture = sfTexture_createFromImage(sheet, &area);
        anim_add_frame(anim, frame_new(texture, frame_id), NULL);
        area.left += size.x / nb_frames;
        ++frame_id;
    }
    sfImage_destroy(sheet);
}

void anim_set_loop(void *anim, sfBool loop)
{
    anim_t *st_anim = anim;

    FAIL_IF_VOID(!anim);
    st_anim->loop = loop;
    while (((frame_t *)st_anim->frames)->index != 0)
        st_anim->frames = ((frame_t *)st_anim->frames)->next;
}

void anim_reset_loop(void *anim)
{
    anim_t *st_anim = anim;

    FAIL_IF_VOID(!anim);
    while (((frame_t *)st_anim->frames)->index != 0)
        st_anim->frames = ((frame_t *)st_anim->frames)->next;
}