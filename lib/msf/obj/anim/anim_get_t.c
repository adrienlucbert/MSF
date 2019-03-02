/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_get_transforms
*/

#include "msf/msf.h"

sfVector2f anim_obj_get_origin(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_anim_obj, origin);
    origin = sfSprite_getOrigin(st_anim_obj->sprite);
    return (origin);
}

sfVector2f anim_obj_get_position(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    sfVector2f position = {0, 0};
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_anim_obj, position);
    origin = VGET(anim_obj, get_origin);
    position = sfSprite_getPosition(st_anim_obj->sprite);
    position = (sfVector2f){position.x - origin.x, position.y - origin.y};
    return (position);
}

float anim_obj_get_rotation(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    float rotation = 0;

    FAIL_IF(!st_anim_obj, rotation);
    rotation = sfSprite_getRotation(st_anim_obj->sprite);
    return (rotation);
}

sfVector2f anim_obj_get_scale(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    sfVector2f scale = {0, 0};

    FAIL_IF(!st_anim_obj, scale);
    scale = sfSprite_getScale(st_anim_obj->sprite);
    return (scale);
}

sfVector2u anim_obj_get_size(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    anim_t *st_anim = NULL;
    frame_t *st_frame = NULL;
    sfVector2u size = {0, 0};
    sfVector2f scale = {0, 0};


    FAIL_IF(!st_anim_obj, size);
    st_anim = (anim_t *)st_anim_obj->anims;
    FAIL_IF(!st_anim, size);
    st_frame = (frame_t *)st_anim->frames;
    size = sfTexture_getSize(st_frame->texture);
    scale = VGET(anim_obj, get_scale);
    size = (sfVector2u){size.x * scale.x, size.y * scale.y};
    return (size);
}