/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** input_set
*/

#include "msf/msf.h"

void input_obj_set_value(void *input_obj, void *value)
{
    input_obj_t *st_input_obj = (input_obj_t *)input_obj;

    if (st_input_obj != NULL) {
        if (st_input_obj->value)
            free(st_input_obj->value);
        if (value != NULL) {
            st_input_obj->value = my_memdup(value, -1);
        } else {
            st_input_obj->value = NULL;
        }
    }
}