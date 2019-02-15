/*
** EPITECH PROJECT, 2018
** Libmy
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(char const *str)
{
    int index = 0;

    if (!str)
        return;
    while (str[index] != '\0') {
        my_putchar(str[index]);
        index = index + 1;
    }
}