/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** text_get_t
*/

#include "msf/msf.h"

sfVector2f text_obj_get_origin(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    sfVector2f origin = {0, 0};

    FAIL_IF(!st_text_obj, origin);
    origin = sfText_getOrigin(st_text_obj->text);
    return (origin);
}

sfVector2f text_obj_get_position(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    sfVector2f position = {0, 0};

    FAIL_IF(!st_text_obj, position);
    position = sfText_getPosition(st_text_obj->text);
    return (position);
}

float text_obj_get_rotation(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    float rotation = 0;

    FAIL_IF(!st_text_obj, rotation);
    rotation = sfText_getRotation(st_text_obj->text);
    return (rotation);
}

sfVector2f text_obj_get_scale(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    sfVector2f scale = {0, 0};

    FAIL_IF(!st_text_obj, scale);
    scale = sfText_getScale(st_text_obj->text);
    return (scale);
}

sfVector2u text_obj_get_size(void *text_obj)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    sfFloatRect bounds;
    sfVector2u size = {0, 0};

    FAIL_IF(!st_text_obj, size);
    bounds = sfText_getGlobalBounds(st_text_obj->text);
    size.x = bounds.width;
    size.y = bounds.height;
    return (size);
}