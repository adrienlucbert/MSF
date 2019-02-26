/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** input_get_t
*/

#include "msf/msf.h"

sfFloatRect input_obj_get_box(void *input_obj)
{
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;
    sfFloatRect box = {0, 0, 0, 0};

    if (st_input_obj->background) {
        box = VGET(st_input_obj->background, get_box);
    } else if (st_input_obj->foreground) {
        box = VGET(st_input_obj->foreground, get_box);
    }
    return (box);
}