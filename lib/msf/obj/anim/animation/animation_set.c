/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_set
*/

#include "msf/msf.h"
#include <stdio.h>

void anim_set_frames(void *anim, hub_t *hub, char *image, int nb_frames)
{
    FAIL_IF_VOID(!hub || !image)
    image_t *st_image = hub && image ? list_fetch(hub->images, image) : NULL;
    sfImage *sheet = st_image ? st_image->sheet : NULL;
    sfVector2u size = sheet ? sfImage_getSize(sheet) : VECT2U(0, 0);
    sfIntRect area;
    sfTexture *texture = NULL;
    int frame_id = 0;

    FAIL_IF_VOID(nb_frames <= 0);
    area = RECT2I(0, 0, size.x / nb_frames, size.y);
    FAIL_IF_VOID(!hub || !image || !st_image || !sheet);
    while (frame_id < nb_frames) {
        texture = sfTexture_createFromImage(sheet, &area);
        anim_add_frame(anim, frame_new(texture, frame_id), NULL);
        area.left += size.x / nb_frames;
        ++frame_id;
    }
    sfImage_destroy(sheet);
}

void anim_set_frame_duration(void *anim, uint duration)
{
    anim_t *st_anim = anim;

    FAIL_IF_VOID(!anim);
    st_anim->frame_duration = duration;
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