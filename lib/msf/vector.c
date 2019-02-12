/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** vector
*/

#include "msf/msf.h"

sfVector2f vectorf_new(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2i vectori_new(int x, int y)
{
    sfVector2i vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2u vectoru_new(uint x, uint y)
{
    sfVector2u vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}