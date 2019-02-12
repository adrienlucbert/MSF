/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** evt_tor
*/

#include "msf/msf.h"

void *evt_new(void (*fn)(hub_t *, sfEvent), evt_scope scope)
{
    evt_t *st_evt = malloc(sizeof(evt_t));

    FAIL_IF(!st_evt, NULL);
    evt_ctor(st_evt, fn, scope);
    return ((void *)st_evt);
}

void *evt_ctor(void *evt, void (*fn)(hub_t *, sfEvent), evt_scope scope)
{
    evt_t *st_evt = (evt_t *)evt;

    FAIL_IF(!st_evt, NULL);
    st_evt->scope = scope;
    st_evt->evt = fn;
    st_evt->dtor = NULL;
    return (evt);
}

void evt_destroy(void *evt)
{
    free(evt);
}