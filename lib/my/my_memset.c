/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *tmp = s;

    while (n > 0) {
        *tmp = (char)c;
        ++tmp;
        --n;
    }
    return (s);
}