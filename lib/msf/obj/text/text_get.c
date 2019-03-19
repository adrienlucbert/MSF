/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** text_get
*/

#include "msf/msf.h"

sfFloatRect text_obj_get_box(void *text)
{
    text_obj_t *st_text = (text_obj_t *)text;
    sfVector2f origin = VGET(st_text, get_origin);
    sfVector2f pos = VGET(st_text, get_position);
    sfVector2u size = VGET(st_text, get_size);
    sfVector2f scale = VGET(st_text, get_scale);
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF(!st_text, box);
    box.left = pos.x - origin.x;
    box.top = pos.y - origin.x;
    box.width = size.x * scale.x;
    box.height = size.y * scale.y;
    return (box);
}