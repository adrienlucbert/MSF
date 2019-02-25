/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** input_set_t
*/

#include "msf/msf.h"

void input_set_origin(void *input, sfVector2f origin)
{
    input_obj_t *st_input = (input_obj_t *)input;

    FAIL_IF_VOID(!st_input);
    VFUNC(st_input->background, set_origin, origin);
    VFUNC(st_input->foreground, set_origin, origin);
}

void input_set_position(void *input, sfVector2f position)
{
    input_obj_t *st_input = (input_obj_t *)input;

    FAIL_IF_VOID(!st_input);
    VFUNC(st_input->background, set_position, position);
    VFUNC(st_input->foreground, set_position, position);
}

void input_set_rotation(void *input, float rotation)
{
    input_obj_t *st_input = (input_obj_t *)input;

    FAIL_IF_VOID(!st_input);
    VFUNC(st_input->background, set_rotation, rotation);
    VFUNC(st_input->foreground, set_rotation, rotation);
}

void input_set_scale(void *input, sfVector2f scale)
{
    input_obj_t *st_input = (input_obj_t *)input;

    FAIL_IF_VOID(!st_input);
    VFUNC(st_input->background, set_scale, scale);
    VFUNC(st_input->foreground, set_scale, scale);
}

void input_set_size(void *input, sfVector2u size)
{
    input_obj_t *st_input = (input_obj_t *)input;

    FAIL_IF_VOID(!st_input);
    VFUNC(st_input->background, set_size, size);
    VFUNC(st_input->foreground, set_size, size);
}