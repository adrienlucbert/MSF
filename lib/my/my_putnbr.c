/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** my_putnbr
*/

#include "my.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + 48);
}