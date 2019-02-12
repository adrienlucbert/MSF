/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_itoa
*/

#include "my.h"

char *my_itoa(int nb)
{
    char *str = NULL;
    int tmp = nb;
    int len = 0;

    if (nb == 0)
        return (my_memdup("0", sizeof(char)));
    while (tmp >= 10) {
        tmp /= 10;
        ++len;
    }
    str = malloc(sizeof(char) * (len + 2));
    tmp = len;
    while (nb >= 1) {
        str[tmp] = nb % 10 + 48;
        nb = nb / 10;
        --tmp;
    }
    str[len + 1] = '\0';
    return (str);
}