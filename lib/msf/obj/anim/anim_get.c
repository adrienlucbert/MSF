/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_get
*/

#include "msf/msf.h"

sfFloatRect anim_obj_get_box(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;
    sfVector2f pos = VGET(st_anim_obj, get_position);
    sfVector2u size = VGET(st_anim_obj, get_size);
    sfVector2f scale = VGET(st_anim_obj, get_scale);
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF(!st_anim_obj, box);
    box.left = pos.x;
    box.top = pos.y;
    box.width = size.x * scale.x;
    box.height = size.y * scale.y;
    return (box);
}