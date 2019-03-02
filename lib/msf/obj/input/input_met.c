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
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;
    obj_t *bg = st_input_obj->background;
    obj_t *fg = st_input_obj->foreground;
    sfFloatRect fg_box = {0, 0, 0, 0};
    sfFloatRect bg_box = {0, 0, 0, 0};
    sfVector2f pos = {0, 0};

    if (bg)
        bg_box = VGET(bg, get_box);
    if (fg)
        fg_box = VGET(fg, get_box);
    pos = (sfVector2f){fg_box.left, fg_box.top - fg_box.height / 2};
    VFUNC(bg, set_origin, (sfVector2f){bg_box.width / 2, bg_box.height / 2});
    VFUNC(fg, set_origin, (sfVector2f){fg_box.width / 2, fg_box.height / 2});
    VFUNC(fg, set_position, pos);
}