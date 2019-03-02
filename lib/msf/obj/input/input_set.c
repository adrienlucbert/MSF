/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** input_set
*/

#include "msf/msf.h"

void input_obj_set_activity(void *input_obj, void (*on_active)(hub_t *, void *))
{
    input_obj_t *st_input = input_obj;

    st_input->on_active = on_active;
}