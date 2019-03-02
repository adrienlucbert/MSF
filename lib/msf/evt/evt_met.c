/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** evt_met
*/

#include "msf/msf.h"

void evt_trigger_scope(void *evts, evt_scope scope, hub_t *hub, sfEvent data)
{
    evt_t *curr = (evt_t *)evts;
    evt_t *next = NULL;

    FAIL_IF_VOID(!curr || !hub);
    next = curr->next;
    while (next != evts) {
        if (curr->scope == scope)
            evt_trigger(curr, hub, data);
        curr = next;
        next = next->next;
    };
    if (curr->scope == scope)
        evt_trigger(curr, hub, data);
}

void evt_trigger(void *evt, hub_t *hub, sfEvent data)
{
    evt_t *st_evt = (evt_t *)evt;

    FAIL_IF_VOID(!evt || !hub);
    st_evt->evt(hub, data);
}