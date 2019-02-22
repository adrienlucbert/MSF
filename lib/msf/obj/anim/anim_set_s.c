/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_set_style
*/

#include "msf/msf.h"

void anim_obj_set_texture(void *anim_obj, sfTexture *texture, sfBool reset)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    FAIL_IF_VOID(!st_anim_obj);
    sfSprite_setTexture(st_anim_obj->sprite, texture, reset);
}