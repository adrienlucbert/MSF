/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** text_set_t
*/

#include "msf/msf.h"

void text_obj_set_origin(void *text_obj, sfVector2f origin)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setOrigin(st_text_obj->text, origin);
}

void text_obj_set_position(void *text_obj, sfVector2f position)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setPosition(st_text_obj->text, position);
}

void text_obj_set_rotation(void *text_obj, float angle)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setRotation(st_text_obj->text, angle);
}

void text_obj_set_scale(void *text_obj, sfVector2f scale)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj);
    sfText_setScale(st_text_obj->text, scale);
}

void text_obj_set_size(void *text_obj, sfVector2u size)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;
    sfVector2f actual_scale;
    sfVector2u actual_size;
    sfVector2f new_scale;

    FAIL_IF_VOID(!st_text_obj);
    actual_scale = text_obj_get_scale(text_obj);
    actual_size = text_obj_get_size(text_obj);
    FAIL_IF_VOID(actual_size.x == 0 || actual_size.y == 0);
    new_scale.x = size.x * actual_scale.x / actual_size.x;
    new_scale.y = size.y * actual_scale.y / actual_size.y;
    text_obj_set_scale(text_obj, new_scale);
}