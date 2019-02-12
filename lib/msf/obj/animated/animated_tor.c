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

void *anim_obj_ctor(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    FAIL_IF(!st_anim_obj, NULL);
    obj_ctor(st_anim_obj, animated);
    st_anim_obj->anims = NULL;
    st_anim_obj->dtor = anim_obj_dtor;
    return (anim_obj);
}

void anim_obj_dtor(void *anim_obj)
{
    anim_obj_t *st_anim_obj = (anim_obj_t *)anim_obj;

    obj_dtor(anim_obj);
    list_destroy(st_anim_obj->anims);
}

void anim_obj_destroy(void *anim_obj)
{
    anim_obj_dtor(anim_obj);
    free(anim_obj);
}