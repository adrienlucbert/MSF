/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** physics_met
*/

#include "msf/msf.h"

void physics_reset(void *physics)
{
    obj_physics_t *st_physics = (obj_physics_t *)physics;

    st_physics->angle = 0;
}

void physics_apply(void *physics)
{
    
    // if (position.y + size.y + st_physics->speed.y >= sfRenderWindow_getSize(hub->window).y) {
    //     st_physics->speed.x *= st_physics->restitution;
    //     st_physics->speed.y = -st_physics->speed.y * st_physics->restitution;
    //     physics_reset(st_physics);
    // } else {
    //     st_physics->speed.y += st_obj->physics->gravity;
    // }
}