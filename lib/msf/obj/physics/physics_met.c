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