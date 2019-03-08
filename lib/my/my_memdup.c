/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_memdup
*/

#include "my.h"

void *my_memdup(const void *src, size_t n)
{
    int len = 0;
    void *dest = NULL;

    if (n == (size_t)-1) {
        len = my_memlen(src, sizeof(char)) + 1;
        dest = my_calloc(len, sizeof(char));
    } else {
        dest = my_calloc(n + 1, sizeof(char));
    }
    if (dest)
        my_memcpy(dest, src, n);
    return (dest);
}