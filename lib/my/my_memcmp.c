/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_memcmp
*/

#include "my.h"

int my_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t index = 0;
    char *c_s1 = (char *)s1;
    char *c_s2 = (char *)s2;

    if (!c_s1 && !c_s2)
        return (0);
    if (!c_s1)
        return (-c_s2[0]);
    else if (!c_s2)
        return (c_s1[0]);
    while ((index < n || n == -1) && c_s1 && c_s2) {
        if (c_s1[index] != c_s2[index] || (!c_s1[index] && !c_s2[index]))
            return (c_s1[index] - c_s2[index]);
        ++index;
    }
    return (0);
}