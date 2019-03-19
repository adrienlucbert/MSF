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
    anim_t *st_anim = st_anim_obj ? (anim_t *)st_anim_obj->anims : NULL;

    FAIL_IF_VOID(!st_anim_obj)
    FAIL_IF_VOID(st_anim->frames == ((frame_t *)st_anim->frames)->next);
    st_anim_obj->elapsed += sfClock_getElapsedTime(hub->timer).microseconds;
    while (st_anim_obj->elapsed >= st_anim->frame_duration * 1000) {
        st_anim->frames = ((frame_t *)st_anim->frames)->next;
        if (!st_anim->loop && ((frame_t *)st_anim->frames)->index == 0) {
            st_anim_obj->state = sfFalse;
            st_anim_obj->elapsed = 0;
            return;
        }
        st_anim_obj->elapsed -= st_anim->frame_duration * 1000;
    }
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