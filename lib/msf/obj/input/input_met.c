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
    obj_t *bg = st_input_obj ? st_input_obj->background : NULL;
    obj_t *fg = st_input_obj ? st_input_obj->foreground : NULL;
    sfVector2u size;
    sfVector2f ori;
    sfVector2f scale;

    if (bg) {
        scale = VGET(bg, get_scale);
        size = VGET(bg, get_size);
        ori.x = size.x / 2 / scale.x;
        ori.y = size.y / 2 / scale.y;
        VFUNC(bg, set_origin, ori);
    }
    if (fg) {
        scale = VGET(fg, get_scale);
        size = VGET(fg, get_size);
        ori.x = size.x / 2 / scale.x;
        ori.y = size.y / ((fg->type == text) ? 1 : 2) / scale.y;
        VFUNC(fg, set_origin, ori);
    }
}

void input_obj_auto_scale_fg(input_obj_t *st_input)
{
    sfVector2u bg_size;
    sfVector2u fg_size;
    float bg_max = 0.0;
    float fg_max = 0.0;
    float ratio = 1.0;

    FAIL_IF_VOID(!st_input || !st_input->background || !st_input->foreground)
    bg_size = VGET(st_input->background, get_size);
    fg_size = VGET(st_input->foreground, get_size);
    bg_max = bg_size.x > bg_size.y ? bg_size.x : bg_size.y;
    fg_max = fg_size.x > fg_size.y ? fg_size.x : fg_size.y;
    FAIL_IF_VOID(fg_max < bg_max * 0.80);
    ratio = bg_max * 0.80 / fg_max;
    VFUNC(st_input->foreground, set_scale, VECT2F(ratio, ratio));
}