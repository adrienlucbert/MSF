/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** vector
*/

#include "msf/msf.h"

sfVector2f vector_rotate(sfVector2f v0, float angle)
{
    sfVector2f v1 = {0, 0};

    v1.x = v0.x * cos(RAD(angle)) - v0.y * sin(RAD(angle));
    v1.y = v0.x * sin(RAD(angle)) + v0.y * cos(RAD(angle));
    return (v1);
}

sfVector2f vector_add(sfVector2f v0, sfVector2f v1)
{
    return ((sfVector2f){v0.x + v1.x, v0.y + v1.y});
}

sfVector2f vector_sub(sfVector2f v0, sfVector2f v1)
{
    return ((sfVector2f){v0.x - v1.x, v0.y - v1.y});
}

sfVector2f vector_mul(sfVector2f v0, sfVector2f v1)
{
    return ((sfVector2f){v0.x * v1.x, v0.y * v1.y});
}

float vector_magnitude(sfVector2f v)
{
    return (sqrt(v.x * v.x + v.y * v.y));
}

float angle_between_vectors(sfVector2f v0, sfVector2f v1)
{
    float rad = atan2(v1.y, v1.x) - atan2(v0.y, v0.x);

    return (DEG(rad));
}

float dot_product(sfVector2f v0, sfVector2f v1)
{
    float prod = 0;

    prod = v0.x * v1.x + v0.y * v1.y;
    return (prod);
}

sfVector2f vector_normalize(sfVector2f v0)
{
    sfVector2f v1 = v0;
    float norm = sqrt(v0.x * v0.x + v0.y * v0.y);

    v1.x /= norm;
    v1.y /= norm;
    return (v1);
}

void physics_repulse(manifold_t *m)
{
    obj_physics_t *a = m->phy_a;
    obj_physics_t *b = m->phy_b;
    // sfVector2f n = m->normal;
    // sfVector2f rv = (sfVector2f){a->speed.x - b->speed.x, a->speed.y - b->speed.y};
    // float ps = rv.x * n.x + rv.y * n.y;
    // sfVector2f p = (sfVector2f){n.x * ps, n.y * ps};
    // sfVector2f t = (sfVector2f){rv.x - p.x, rv.y - p.y};
    // float r = fmax(a->restitution, b->restitution);
    // float f = 0;

    // a->speed.x = a->speed.x - p.x * r + t.x * f;
    // a->speed.y = -(a->speed.y - p.y * r + t.y * f);
    // b->speed.x += a->speed.x - p.x * r + t.x * f;
    // b->speed.y += b->speed.y - p.y * r + t.y * f;
    // a->speed.x -= (p.x * r + t.x * f);
    // a->speed.y += (p.y * r + t.y * f);
    // if (b->mass != 0) {
    //     b->speed.x -= (p.x * r + t.x * f) * b->inv_mass;
    //     b->speed.y += (p.y * r + t.y * f) * b->inv_mass;
    // }

    // sfVector2f rv = {b->speed.x - a->speed.x, b->speed.y - a->speed.y};
    // float contact_vel = dot_product(rv, m->normal);

    // FAIL_IF_VOID(contact_vel > 0);
 
    // // Calculate restitution
    // float e = fmin(a->restitution, b->restitution);
 
    // // Calculate impulse scalar
    // float j = -(1.0 + e) * contact_vel;
    // if (a->inv_mass + b->inv_mass != 0)
    //     j /= a->inv_mass + b->inv_mass;
    
    // // Apply impulse
    // sfVector2f impulse = {j * m->normal.x, j * m->normal.y};
    // if (b->speed.x == 0 && b->speed.y == 0)
    //     impulse = (sfVector2f){0, 0};
    // a->speed.x = a->speed.x * a->restitution - a->inv_mass * impulse.x;
    // a->speed.y = - a->speed.y * a->restitution - a->inv_mass * impulse.y;
    // if (b->mass != 0) {
    //     b->speed.x += b->inv_mass * impulse.x;
    //     b->speed.y += b->inv_mass * impulse.y;
    // }
    a->speed.x = 0; 
    a->speed.y = -a->speed.y * a->restitution;
}