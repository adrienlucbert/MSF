/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** animated_tor
*/

#include "msf/msf.h"

void *anim_obj_new(void)
{
    anim_obj_t *st_anim_obj = malloc(sizeof(anim_obj_t));

    FAIL_IF(!st_anim_obj, NULL);
    anim_obj_ctor(st_anim_obj);
    return ((void *)st_anim_obj);
}

void anim_obj_ctor(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    FAIL_IF_VOID(!st_anim_obj);
    obj_ctor(st_anim_obj, animated);
    st_anim_obj->anims = NULL;
    st_anim_obj->vtable = anim_obj_vtable_new();
    st_anim_obj->dtor = anim_obj_dtor;
    st_anim_obj->sprite = sfSprite_create();
    st_anim_obj->timer = sfClock_create();
}

void anim_obj_dtor(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    obj_dtor(anim_obj);
    list_destroy(st_anim_obj->anims);
    sfClock_destroy(st_anim_obj->timer);
    sfSprite_destroy(st_anim_obj->sprite);
}

void anim_obj_destroy(void *anim_obj)
{
    anim_obj_dtor(anim_obj);
    free(anim_obj);
}