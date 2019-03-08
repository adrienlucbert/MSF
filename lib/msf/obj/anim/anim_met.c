/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** animated_met
*/

#include "msf/msf.h"
#include <stdio.h>

void anim_obj_add_anim(void *obj, void *anim, char *label)
{
    anim_obj_t *st_obj = (anim_obj_t *)obj;

    node_ctor(anim, label, NULL);
    list_append(&st_obj->anims, anim);
}

void anim_obj_animate(hub_t *hub, void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    anim_t *st_anim = NULL;
    frame_t *st_frame = NULL;
    float elapsed_time = 0;
    int i = 0;

    FAIL_IF_VOID(!st_anim_obj || !(anim_t *)st_anim_obj->anims);
    st_anim = (anim_t *)st_anim_obj->anims;
    st_frame = (frame_t *)st_anim->frames;
    FAIL_IF_VOID(!st_frame || st_frame->next == st_frame);
    elapsed_time = sfClock_getElapsedTime(hub->timer).microseconds / 1000;
    elapsed_time += st_anim_obj->elapsed / 1000;
    while (elapsed_time >= st_anim->frame_duration) {
        st_anim->frames = st_frame->next;
        elapsed_time -= st_anim->frame_duration;
        ++i;
    }
    st_anim_obj->elapsed = elapsed_time * 1000;
}

void anim_obj_render(void *anim_obj, hub_t *hub)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    anim_t *st_anim = NULL;
    frame_t *st_frame = NULL;

    FAIL_IF_VOID(!st_anim_obj || !st_anim_obj->sprite || !hub);
    st_anim = (anim_t *)st_anim_obj->anims;
    FAIL_IF_VOID(!st_anim || !st_anim->frames);
    st_frame = (frame_t *)st_anim->frames;
    anim_obj_animate(hub, anim_obj);
    sfSprite_setTexture(st_anim_obj->sprite, st_frame->texture, sfTrue);
    sfRenderWindow_drawSprite(hub->window, st_anim_obj->sprite, NULL);
}