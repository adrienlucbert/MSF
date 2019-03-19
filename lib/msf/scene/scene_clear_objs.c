/*
** EPITECH PROJECT, 2019
** msf
** File description:
** scene_clear_objs
*/

#include "msf/msf.h"

static void scene_pointer_to_objs_check(scene_t *scene)
{
    obj_t *tmp = NULL;
    int check = 0;

    FAIL_IF_VOID(!scene || scene->objs);
    tmp = ((obj_t *)scene->objs)->next;
    check = ((obj_t *)scene->objs)->is_alive ? 1 : 0;
    while (!check && tmp && tmp != scene->objs) {
        if (tmp->is_alive) {
            scene->objs = tmp;
            check = 1;
        }
        tmp = tmp->next;
    }
}

void scene_clear_objs(scene_t *scene)
{
    obj_t *objs = scene && scene->objs ? ((obj_t *)scene->objs)->next : NULL;

    FAIL_IF_VOID(!scene || !objs);
    scene_pointer_to_objs_check(scene);
    obj_t *prev = scene->objs;
    obj_t *curr = objs;
    obj_t *next = objs->next;

    while (next != objs) {
        if (!curr->is_alive) {
            prev->next = next;
            node_destroy(curr);
            curr = prev;
        }
        prev = curr;
        curr = next;
        next = next->next;
    }
    if (!curr->is_alive)
        node_destroy(curr);
}