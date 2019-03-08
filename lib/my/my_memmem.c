/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_memmem
*/

#include "my.h"

void *my_memmem(void const *hay, size_t h_len, void const *nee, size_t n_len)
{
    char *c_haystack = (char *)hay;
    char *c_needle = (char *)nee;

    h_len = h_len == (size_t)-1 ? (size_t)my_memlen(hay, sizeof(char)) : h_len;
    n_len = n_len == (size_t)-1 ? (size_t)my_memlen(nee, sizeof(char)) : n_len;
    if (n_len == 0)
        return ((void *)c_haystack);
    c_haystack = my_memchr(hay, *c_needle, h_len);
    if (!c_haystack)
        return (NULL);
    h_len -= c_haystack - (char *)hay;
    if (h_len < n_len)
        return (NULL);
    if (my_memcmp(c_haystack, c_needle, n_len) == 0)
        return ((void *)c_haystack);
    else
        return (my_memmem((void *)c_haystack, h_len, nee, n_len));
}