/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** animated_met
*/

#include "msf/msf.h"

void obj_add_anim(void *obj, void *anim, char *label)
{
    anim_obj_t *st_obj = (anim_obj_t *)obj;

    node_ctor(anim, label, NULL);
    list_append(st_obj->anims, anim);
}

void obj_animated_render(hub_t *hub, void *obj)
{
    hub = hub;
    obj = obj;
}