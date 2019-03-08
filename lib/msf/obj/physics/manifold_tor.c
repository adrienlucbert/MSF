/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** manifold_tor
*/

#include "msf/msf.h"

void *manifold_new(void *phy_a, obj_physics_t *phy_b)
{
    manifold_t *manifold = malloc(sizeof(manifold_t));

    FAIL_IF(!manifold, NULL);
    manifold_ctor(manifold, phy_a, phy_b);
    return ((void *)manifold);
}

void manifold_ctor(void *manifold, obj_physics_t *phy_a, obj_physics_t *phy_b)
{
    manifold_t *st_manifold = (manifold_t *)manifold;

    st_manifold->phy_a = phy_a;
    st_manifold->phy_b = phy_b;
    st_manifold->penetration = 0;
    st_manifold->normal = VECT2F(0, 0);
}

void manifold_destroy(void *manifold)
{
    free(manifold);
}