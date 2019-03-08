/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_memchr
*/

#include "my.h"

void *my_memchr(const void *s, int c, size_t n)
{
    char *c_s = (char *)s;
    size_t index = 0;

    while ((index < n || n == (size_t)-1) && c_s && c_s[index]) {
        if (c_s[index] == (char)c)
            return (&c_s[index]);
        ++index;
    }
    return (NULL);
}