/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** container_set
*/

#include "msf/msf.h"

void obj_container_set_texture(void *obj, sfTexture *texture, sfBool reset)
{
    obj_container_t *st_obj_container = (obj_container_t *)obj;
    anim_obj_t *buffer = NULL;

    while (list_poll(st_obj_container->objs, (void **)&buffer)) {
        sfSprite_setTexture(buffer->sprite, texture, reset);
    }
}