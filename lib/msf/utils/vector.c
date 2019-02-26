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