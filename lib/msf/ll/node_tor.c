/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** node_tor
*/

#include "msf/msf.h"

void *node_new(char *label, void *next)
{
    node_t *st_node = malloc(sizeof(node_t));

    FAIL_IF(!st_node, NULL);
    node_ctor(st_node, label, next);
    return ((void *)st_node);
}

void *node_ctor(void *node, char *label, void *next)
{
    node_t *st_node = (node_t *)node;

    FAIL_IF(!st_node, NULL);
    st_node->label = my_memdup(label, -1);
    st_node->next = next == NULL ? st_node : next;
    return (node);
}

void node_dtor(void *node)
{
    node_t *st_node = (node_t *)node;

    if (st_node->label) {
        free(st_node->label);
        st_node->label = NULL;
    }
    if (st_node->dtor) {
        st_node->dtor(node);
    }
}

void node_destroy(void *node)
{
    node_dtor(node);
    free(node);
}