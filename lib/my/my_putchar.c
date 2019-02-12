/*
** EPITECH PROJECT, 2018
** Libmy
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}