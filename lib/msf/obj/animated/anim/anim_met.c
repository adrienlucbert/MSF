/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_met
*/

#include "msf/msf.h"

void anim_add_frame(void *anim, void *frame, char *label)
{
    anim_t *st_anim = (anim_t *)anim;

    FAIL_IF_VOID(!st_anim || !frame);
    node_ctor(frame, label, NULL);
    list_append(&st_anim->frames, frame);
}