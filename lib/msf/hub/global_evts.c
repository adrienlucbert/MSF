/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** global_evts
*/

#include "msf/msf.h"

void window_close_evt(hub_t *hub, sfEvent evt)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(hub->window);
}

void mouse_evt_updater(void *obj, sfEvent evt)
{
    obj_t *st_obj = (obj_t *)obj;
    sfVector2f mouse = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF_VOID(!st_obj);
    box = VGET(obj, get_box);
    if (evt.type == sfEvtMouseMoved) {
        mouse = (sfVector2f){evt.mouseMove.x, evt.mouseMove.y};
        if (sfFloatRect_contains(&box, mouse.x, mouse.y)) {
            st_obj->mouse_evt->hover = sfTrue;
            st_obj->mouse_evt->x = mouse.x;
            st_obj->mouse_evt->y = mouse.y;
        } else {
            st_obj->mouse_evt->hover = sfFalse;
        }
    }
    if (evt.type == sfEvtMouseButtonPressed) {
        mouse = (sfVector2f){evt.mouseButton.x, evt.mouseButton.y};
        if (sfFloatRect_contains(&box, mouse.x, mouse.y)) {
            st_obj->mouse_evt->active = sfTrue;
            st_obj->mouse_evt->focus = sfTrue;
            st_obj->mouse_evt->x = mouse.x;
            st_obj->mouse_evt->y = mouse.y;
        } else {
            st_obj->mouse_evt->active = sfFalse;
            st_obj->mouse_evt->focus = sfFalse;
        }
    }
    if (evt.type == sfEvtMouseButtonReleased) {
        st_obj->mouse_evt->active = sfFalse;
    }

    printf("%s\n", st_obj->label);
    printf("hover\t%s\n", (st_obj->mouse_evt->hover ? "true" : "false"));
    printf("focus\t%s\n", (st_obj->mouse_evt->focus ? "true" : "false"));
    printf("active\t%s\n", (st_obj->mouse_evt->active ? "true" : "false"));
    printf("x\t%d\ty\t%d\n\n", st_obj->mouse_evt->x, st_obj->mouse_evt->y);
}

void mouse_evt_updater_evt(hub_t *hub, sfEvent evt)
{
    obj_t *begin = NULL;
    obj_t *curr = NULL;
    obj_t *next = NULL;

    FAIL_IF_VOID(evt.type != 11 && evt.type != 9 && evt.type != 10);
    FAIL_IF_VOID(!hub || !hub->scenes || !((scene_t *)hub->scenes)->objs);
    begin = ((scene_t *)hub->scenes)->objs;
    curr = begin;
    next = curr->next;
    while (next != begin) {
        mouse_evt_updater(curr, evt);
        curr = next;
        next = (obj_t *)next->next;
    };
    mouse_evt_updater(curr, evt);
}