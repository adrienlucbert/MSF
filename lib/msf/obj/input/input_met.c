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

void input_obj_recenter(void *input_obj)
{
    input_obj_t *st_input = input_obj;
    sfVector2u frg_size = VGET(st_input->foreground, get_size);
    sfVector2u bck_size = VGET(st_input->background, get_size);
    sfVector2f bck_pos = VGET(st_input->background, get_position);
    sfVector2f frg_pos = VGET(st_input->foreground, get_position);

    frg_pos.x = (bck_pos.x + (bck_size.x / 2)) - (frg_size.x / 2);
    frg_pos.y = (bck_pos.y + (bck_size.y / 2)) - (frg_size.y / 2);
    VFUNC(st_input->foreground, set_position, frg_pos);
}