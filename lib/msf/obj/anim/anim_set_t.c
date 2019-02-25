/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_set_transforms
*/

#include "msf/msf.h"

void anim_obj_set_origin(void *anim_obj, sfVector2f origin)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    FAIL_IF_VOID(!st_anim_obj);
    sfSprite_setOrigin(st_anim_obj->sprite, origin);
}

void anim_obj_set_position(void *anim_obj, sfVector2f position)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    FAIL_IF_VOID(!st_anim_obj);
    st_anim_obj->physics->pos = position;
    sfSprite_setPosition(st_anim_obj->sprite, position);
}

void anim_obj_set_rotation(void *anim_obj, float angle)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    FAIL_IF_VOID(!st_anim_obj);
    sfSprite_setRotation(st_anim_obj->sprite, angle);
}

void anim_obj_set_scale(void *anim_obj, sfVector2f scale)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    FAIL_IF_VOID(!st_anim_obj);
    sfSprite_setScale(st_anim_obj->sprite, scale);
}

void anim_obj_set_size(void *anim_obj, sfVector2u size)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    sfVector2f actual_scale;
    sfVector2u actual_size;
    sfVector2f new_scale;

    FAIL_IF_VOID(!st_anim_obj);
    actual_scale = anim_obj_get_scale(anim_obj);
    actual_size = anim_obj_get_size(anim_obj);
    FAIL_IF_VOID(actual_size.x == 0 || actual_size.y == 0);
    new_scale.x = size.x * actual_scale.x / actual_size.x;
    new_scale.y = size.y * actual_scale.y / actual_size.y;
    st_anim_obj->physics->size.x = actual_size.x * new_scale.x;
    st_anim_obj->physics->size.y = actual_size.y * new_scale.y;
    anim_obj_set_scale(anim_obj, new_scale);
}