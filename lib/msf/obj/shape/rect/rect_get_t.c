/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** rect_get_t
*/

#include "msf/msf.h"

sfVector2f rect_get_origin(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, origin);
    origin = sfRectangleShape_getOrigin(st_rect->shape);
    return (origin);
}

sfVector2f rect_get_position(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f position = {0, 0};
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, position);
    origin = VGET(rect, get_origin);
    position = sfRectangleShape_getPosition(st_rect->shape);
    position = (sfVector2f){position.x - origin.x, position.y - origin.y};
    return (position);
}

float rect_get_rotation(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    float rotation = 0;

    FAIL_IF(!st_rect || !st_rect->shape, rotation);
    rotation = sfRectangleShape_getRotation(st_rect->shape);
    return (rotation);
}

sfVector2f rect_get_scale(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f scale = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, scale);
    scale = sfRectangleShape_getScale(st_rect->shape);
    return (scale);
}

sfVector2u rect_get_size(void *rect)
{
    shape_obj_t *st_rect = (shape_obj_t *)rect;
    sfVector2f fsize = {0, 0};
    sfVector2u usize = {0, 0};
    sfVector2f scale = {0, 0};

    FAIL_IF(!st_rect || !st_rect->shape, usize);
    scale = VGET(rect, get_scale);
    fsize = sfRectangleShape_getSize(st_rect->shape);
    usize = (sfVector2u){fsize.x * scale.x, fsize.y * scale.y};
    return (usize);
}

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