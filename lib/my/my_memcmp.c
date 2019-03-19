/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_memcmp
*/

#include "my.h"

int my_memcmp(void *m1, void *m2, long n)
{
    long i = 0;
    char *s1 = (char *)m1;
    char *s2 = (char *)m2;

    if (!s1 && !s2)
        return (0);
    if (!s1 || !s2)
        return (-1);
    while (s1[i] && s2[i] && (i < n || n == -1)) {
        if (s1[i] != s2[i])
            return (1);
        ++i;
    }
    if (n == -1 && s1[i] != s2[i])
        return (1);
    return (0);
}