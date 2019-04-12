/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** obj_set_t
*/

#include "msf/msf.h"

static int pop_obj_from_list(void **begin, obj_t *st_obj)
{
    obj_t *tmp = *begin;
    obj_t *prev = NULL;
    obj_t *next = *begin;

    if (tmp == st_obj) {
        while (list_poll(*begin, (void **)&next)) {}
        FAIL_IF(next == st_obj, 0);
        next->next = tmp->next;
        *begin = tmp->next;
        return (1);
    }
    while (next && next->next != *begin && next != st_obj) {
        prev = next;
        next = next->next;
    }
    if (next != st_obj)
        return (0);
    prev->next = next->next;
    return (1);
}

static void obj_place_in_list(void **objs_list, void *obj, int z_index)
{
    obj_t *st_obj = obj;
    obj_t *prev = NULL;
    obj_t *curr = *objs_list;
    int check = 1;

    if (curr->z_index < z_index) {
        while (list_poll(*objs_list, (void **)(&prev))) {}
        prev->next = st_obj;
        st_obj->next = curr;
        *objs_list = st_obj;
        return;
    }
    while (curr->next != *objs_list && check) {
        check = ((obj_t *)curr->next)->z_index < z_index ? 0 : 1;
        curr = ((obj_t *)curr->next)->z_index < z_index ? curr : curr->next;
    }
    prev = curr;
    curr = curr->next;
    prev->next = st_obj;
    st_obj->next = curr;
}

void obj_set_z_index(void **objs_list, void *obj, int z_index)
{
    obj_t *st_obj = obj;

    FAIL_IF_VOID(!st_obj || st_obj->z_index == z_index);
    st_obj->z_index = z_index;
    FAIL_IF_VOID(!objs_list || !pop_obj_from_list(objs_list, st_obj));
    obj_place_in_list(objs_list, obj, z_index);
}