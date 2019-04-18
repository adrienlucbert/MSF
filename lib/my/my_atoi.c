/*
** EPITECH PROJECT, 2018
** Libmy
** File description:
** my_getnbr
*/

#include "my.h"

int my_atoi(char const *str)
{
    int sign = 1;
    int index = 0;
    int nb = 0;

    if (!str)
        return (0);
    while (str[index] == '+' || str[index] == '-') {
        sign = str[index] == '-' ? -sign : sign;
        ++index;
    }
    while (str[index] >= '0' && str[index] <= '9') {
        if (nb < 0)
            return (0);
        nb *= 10;
        nb += str[index] - 48;
        ++index;
    }
    return (sign * nb);
}