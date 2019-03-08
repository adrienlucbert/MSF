/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** vector
*/

#include "msf/msf.h"

sfVector2f vector_normalize(sfVector2f v)
{
    float magnitude = vector_magnitude(v);

    FAIL_IF(magnitude == 0, v);
    v.x /= magnitude;
    v.y /= magnitude;
    return (v);
}

float vector_magnitude(sfVector2f v)
{
    return (sqrt(v.x * v.x + v.y * v.y));
}

float angle_between_vectors(sfVector2f v0, sfVector2f v1)
{
    return (DEG(atan2(v1.y, v1.x) + atan2(v0.y, v0.x)));
}