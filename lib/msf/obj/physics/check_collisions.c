/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** collisions
*/

#include "msf/msf.h"

sfBool obj_collide(hub_t *hub, void *obj_a, void *obj_b)
{
    obj_t *st_obj_a = (obj_t *)obj_a;
    obj_t *st_obj_b = (obj_t *)obj_b;

    FAIL_IF(st_obj_a == st_obj_b, sfFalse);
    FAIL_IF(!st_obj_a || !st_obj_a->physics, sfFalse);
    FAIL_IF(!st_obj_b || !st_obj_b->physics, sfFalse);
    FAIL_IF(!st_obj_b->is_collider, sfFalse);
    manifold_reset(hub->manifold, st_obj_a->physics, st_obj_b->physics);
    return (manifold_collide(hub->manifold));
}

sfBool obj_collide_with_all(hub_t *hub, void *obj)
{
    obj_t *begin = NULL;
    obj_t *curr = NULL;
    sfBool collide = sfFalse;

    FAIL_IF(!hub || !hub->scenes, sfFalse);
    begin = ((scene_t *)hub->scenes)->objs;
    FAIL_IF(!begin, sfFalse);
    while (list_poll(begin, (void **)&curr)) {
        if (obj_collide(hub, obj, curr)) {
            collide = sfTrue;
            return (collide);
        }
    }
    return (collide);
}

sfBool obj_collide_with_group(hub_t *hub, void *obj, int group)
{
    obj_t *begin = NULL;
    obj_t *curr = NULL;
    sfBool collide = sfFalse;

    FAIL_IF(!hub || !hub->scenes, sfFalse);
    begin = ((scene_t *)hub->scenes)->objs;
    FAIL_IF(!begin, sfFalse);
    while (list_poll(begin, (void **)&curr)) {
        if (curr->group == group && obj_collide(hub, obj, curr)) {
            collide = sfTrue;
            return (collide);
        }
    }
    return (collide);
}