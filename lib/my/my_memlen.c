/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_memlen
*/

#include "my.h"

int my_memlen(void const *ptr, size_t size)
{
    char *c_ptr = (char *)ptr;
    size_t len = 0;

    if (ptr == NULL)
        return (0);
    while (c_ptr[len]) {
        len += size;
    }
    return (len / size);
}