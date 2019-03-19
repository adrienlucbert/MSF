/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_get
*/

#include "msf/msf.h"

sfFloatRect rect_get_box(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f pos = VGET(st_rect, get_position);
    sfVector2u size = VGET(st_rect, get_size);
    sfVector2f scale = VGET(st_rect, get_scale);
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF(!st_rect, box);
    box.left = pos.x;
    box.top = pos.y;
    box.width = size.x * scale.x;
    box.height = size.y * scale.y;
    return (box);
}