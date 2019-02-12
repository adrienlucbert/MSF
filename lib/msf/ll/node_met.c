/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** node_met
*/

#include "msf/msf.h"

void node_pop(void *node)
{
    node_t *st_node = (node_t *)node;
    node_t *tmp = st_node;

    if (!node)
        return;
    while (tmp->next != node)
        tmp = (node_t *)tmp->next;
    tmp->next = st_node->next;
    node_destroy(node);
}