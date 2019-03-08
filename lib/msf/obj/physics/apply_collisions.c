/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** apply_collisions
*/

#include "msf/msf.h"

sfBool obj_apply_collision(hub_t *hub, void *obj_a, void *obj_b)
{
    obj_t *st_obj_a = (obj_t *)obj_a;
    sfVector2f normal = hub->manifold->normal;
    sfVector2f speed_a = st_obj_a->physics->speed;
    obj_physics_t *physics_a = st_obj_a->physics;
    sfVector2f pos_a = VGET(st_obj_a, get_position);

    obj_b = obj_b;
    FAIL_IF(physics_a->gravity == 0, sfTrue);
    if (speed_a.x != 0 || speed_a.y != 0)
        pos_a.y -= hub->manifold->penetration * physics_a->inv_mass;
    speed_a.x = 0;
    speed_a.y *= physics_a->restitution * normal.x * physics_a->inv_mass;
    VFUNC(st_obj_a, set_position, pos_a);
    st_obj_a->physics->speed = speed_a;
    return (sfTrue);
}

sfBool obj_apply_collision_with_all(hub_t *hub, void *obj)
{
    obj_t *begin = NULL;
    obj_t *curr = NULL;
    sfBool collide = sfFalse;

    FAIL_IF(!hub || !hub->scenes, sfFalse);
    begin = ((scene_t *)hub->scenes)->objs;
    FAIL_IF(!begin, sfFalse);
    while (list_poll(begin, (void **)&curr)) {
        if (obj_collide(hub, obj, curr)) {
            obj_apply_collision(hub, obj, curr);
            collide = sfTrue;
        }
    }
    return (collide);
}

sfBool obj_apply_collision_with_group(hub_t *hub, void *obj, int group)
{
    obj_t *begin = NULL;
    obj_t *curr = NULL;
    sfBool collide = sfFalse;

    FAIL_IF(!hub || !hub->scenes, sfFalse);
    begin = ((scene_t *)hub->scenes)->objs;
    FAIL_IF(!begin, sfFalse);
    while (list_poll(begin, (void **)&curr)) {
        if (curr->group == group && obj_collide(hub, obj, curr)) {
            obj_apply_collision(hub, obj, curr);
            collide = sfTrue;
        }
    }
    return (collide);
}