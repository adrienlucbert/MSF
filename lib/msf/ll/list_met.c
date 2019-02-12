/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** list_met
*/

#include "msf/msf.h"

void *list_append(void *begin, void *node)
{
    node_t *st_begin = (node_t *)begin;
    node_t *st_node = (node_t *)node;
    node_t *tmp = st_begin;

    FAIL_IF(!st_begin || !st_node, NULL);
    while (tmp->next != st_begin) {
        tmp = (node_t *)tmp->next;
    }
    tmp->next = node;
    st_node->next = begin;
    return (node);
}

void list_destroy(void *begin)
{
    list_apply(begin, &node_destroy);
}

void list_apply(void *begin, void (*func)(void *))
{
    node_t *curr = (node_t *)begin;
    node_t *next = NULL;

    if (!curr || !func)
        return;
    next = curr->next;
    while (next != begin) {
        func((void *)curr);
        curr = next;
        next = (node_t *)next->next;
    };
    func((void *)curr);
}