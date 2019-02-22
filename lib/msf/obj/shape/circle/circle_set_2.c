/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** circle_set
*/

#include "msf/msf.h"

void circle_set_scale(void *rect, sfVector2f scale)
{
    shape_obj_t *st_circle = (shape_obj_t *)rect;

    FAIL_IF_VOID(!st_circle);
    sfCircleShape_setScale(st_circle->shape, scale);
}