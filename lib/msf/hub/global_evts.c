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

void mouse_evt_update_move(void *obj, sfEvent evt)
{
    obj_t *st_obj = (obj_t *)obj;
    sfVector2f mouse = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF_VOID(st_obj->type == sound);
    mouse = VECT2F(evt.mouseMove.x, evt.mouseMove.y);
    box = VGET(obj, get_box);
    if (sfFloatRect_contains(&box, mouse.x, mouse.y)) {
        st_obj->mouse_evt->hover = sfTrue;
        st_obj->mouse_evt->x = mouse.x;
        st_obj->mouse_evt->y = mouse.y;
    } else {
        st_obj->mouse_evt->hover = sfFalse;
    }
}

void mouse_evt_update_button(void *obj, sfEvent evt)
{
    obj_t *st_obj = (obj_t *)obj;
    sfVector2f mouse = {0, 0};
    sfFloatRect box = {0, 0, 0, 0};

    FAIL_IF_VOID(st_obj->type == sound);
    if (evt.type == sfEvtMouseButtonPressed) {
        mouse = VECT2F(evt.mouseButton.x, evt.mouseButton.y);
        box = VGET(obj, get_box);
        if (sfFloatRect_contains(&box, mouse.x, mouse.y)) {
            st_obj->mouse_evt->active = sfTrue;
            st_obj->mouse_evt->focus = sfTrue;
            st_obj->mouse_evt->x = mouse.x;
            st_obj->mouse_evt->y = mouse.y;
        } else {
            st_obj->mouse_evt->active = sfFalse;
            st_obj->mouse_evt->focus = sfFalse;
        }
    } else if (evt.type == sfEvtMouseButtonReleased) {
        st_obj->mouse_evt->active = sfFalse;
    }
}

void mouse_evt_updater(void *obj, sfEvent evt)
{
    obj_t *st_obj = (obj_t *)obj;

    FAIL_IF_VOID(!st_obj || st_obj->type == sound);
    if (evt.type == sfEvtMouseMoved) {
        mouse_evt_update_move(obj, evt);
    }
    if (evt.type == 9 || evt.type == 10) {
        if (st_obj->state) {
            mouse_evt_update_button(obj, evt);
        } else {
            st_obj->mouse_evt->active = sfFalse;
            st_obj->mouse_evt->focus = sfFalse;
            st_obj->mouse_evt->hover = sfFalse;
        }
    }
}

void mouse_evt_updater_evt(hub_t *hub, sfEvent evt)
{
    scene_t *scene = hub->scenes;
    obj_t *begin = scene ? scene->objs : NULL;
    obj_t *curr = NULL;
    int check = 0;

    FAIL_IF_VOID(!begin || (evt.type != 11 && evt.type != 9 && evt.type != 10));
    FAIL_IF_VOID(!hub || !hub->scenes || !((scene_t *)hub->scenes)->objs);
    while (list_poll((void *)begin, (void **)&curr)) {
        mouse_evt_updater(curr, evt);
        check = curr->mouse_evt && curr->on_active ? 1 : 0;
        if (check && (curr->mouse_evt->active || curr->mouse_evt->focus))
            curr->on_active(hub, curr);
        else if (check && curr->mouse_evt->hover)
            curr->on_active(hub, curr);
    }
}