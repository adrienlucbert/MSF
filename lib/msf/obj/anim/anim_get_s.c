/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_get_style
*/

#include "msf/msf.h"

const sfTexture *anim_obj_get_texture(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    const sfTexture *texture = NULL;

    FAIL_IF(!st_anim_obj, texture);
    texture = sfSprite_getTexture(st_anim_obj->sprite);
    return (texture);
}