/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** input_met
*/

#include "msf/msf.h"

void input_obj_render(void *input_obj, hub_t *hub)
{
    input_obj_t *st_input_obj = input_obj;

    FAIL_IF_VOID(!st_input_obj);
    VFUNC(st_input_obj->background, render, hub);
    VFUNC(st_input_obj->foreground, render, hub);
}