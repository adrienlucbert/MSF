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

void anim_obj_render(hub_t *hub, void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    anim_t *st_anim = (anim_t *)st_anim_obj->anims;

    sfRenderWindow_drawSprite(hub->window, st_anim->sprite, NULL);
}