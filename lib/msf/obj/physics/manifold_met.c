/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** manifold_met
*/

#include "msf/msf.h"

void manifold_reset(manifold_t *m, obj_physics_t *phy_a, obj_physics_t *phy_b)
{
    FAIL_IF_VOID(!m);
    m->phy_a = phy_a;
    m->phy_b = phy_b;
    m->penetration = 0;
    m->normal.x = 0;
    m->normal.y = 0;
}

sfBool manifold_collide(manifold_t *m)
{
    FAIL_IF(!m || !m->phy_a || !m->phy_b, sfFalse);
    if (m->phy_a->radius != 0) {
        if (m->phy_b->radius != 0) {
            return (circle_circle_collision(m));
        } else {
            return (aabb_circle_collision(m, sfFalse));
        }
    } else {
        if (m->phy_b->radius != 0) {
            return (aabb_circle_collision(m, sfTrue));
        } else {
            return (aabb_aabb_collision(m));
        }
    }
}

sfBool aabb_aabb_collision(manifold_t *m)
{
    sfVector2f pos_a = m->phy_a->pos;
    sfVector2f pos_b = m->phy_a->pos;
    sfVector2u size_a = m->phy_a->size;
    sfVector2u size_b = m->phy_a->size;
    sfVector2f overlap = {0, 0};

    overlap.x = (size_a.x + size_b.x) / 2 - fabs(pos_b.x - pos_a.x);
    overlap.y = (size_a.y + size_b.y) / 2 - fabs(pos_b.y - pos_a.y);
    FAIL_IF(overlap.x < 0 || overlap.y < 0, sfFalse);
    if (overlap.x > overlap.y) {
        m->normal.x = pos_b.x - pos_a.x < 0 ? 1 : -1;
        m->penetration = overlap.x;
    } else {
        m->normal.y = pos_b.y - pos_a.y < 0 ? 1 : -1;
        m->penetration = overlap.y;
    }
    if (m->normal.x != m->normal.x)
        m->normal.x = 0;
    if (m->normal.y != m->normal.y)
        m->normal.y = 0;
    return (sfTrue);
}

sfBool circle_circle_collision(manifold_t *m)
{
    sfVector2f pos_a = m->phy_a->pos;
    sfVector2f pos_b = m->phy_b->pos;
    float radius_a = m->phy_a->radius;
    float radius_b = m->phy_b->radius;
    sfVector2f a_to_b = {pos_b.x - pos_a.x, pos_b.y - pos_a.y};

    m->penetration = (radius_a + radius_b) - vector_magnitude(a_to_b);
    FAIL_IF(m->penetration < 0, sfFalse);
    m->normal = VECT2F(a_to_b.y, a_to_b.x);
    m->normal = vector_normalize(m->normal);
    if (m->normal.x != m->normal.x)
        m->normal.x = 0;
    if (m->normal.y != m->normal.y)
        m->normal.y = 0;
    return (sfTrue);
}

sfBool aabb_circle_collision(manifold_t *m, sfBool aabb_first)
{
    obj_physics_t *aabb = aabb_first ? m->phy_a : m->phy_b;
    obj_physics_t *circ = aabb_first ? m->phy_b : m->phy_a;
    sfVector2f near;
    sfVector2f near_to_circ;

    near.x = fmax(aabb->pos.x, fmin(circ->pos.x, aabb->pos.x + aabb->size.x));
    near.y = fmax(aabb->pos.y, fmin(circ->pos.y, aabb->pos.y + aabb->size.y));
    near_to_circ = VECT2F(circ->pos.x - near.x, circ->pos.y - near.y);
    m->penetration = circ->radius - vector_magnitude(near_to_circ);
    FAIL_IF(m->penetration < 0, sfFalse);
    m->normal.x = circ->pos.y - near.y;
    m->normal.y = circ->pos.x - near.x;
    m->normal = vector_normalize(m->normal);
    if (m->normal.x != m->normal.x)
        m->normal.x = 0;
    if (m->normal.y != m->normal.y)
        m->normal.y = 0;
    return (sfTrue);
}