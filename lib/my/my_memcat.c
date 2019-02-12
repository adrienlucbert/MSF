/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_memcat
*/

#include "my.h"

void *my_memcat(void *dest, void const *src)
{
    int dest_len = my_memlen(dest, sizeof(char));
    int src_len = my_memlen(src, sizeof(char));

    dest = my_realloc(dest, (dest_len + src_len + 1) * sizeof(char));
    my_memcpy(dest + dest_len, src, src_len);
    return (dest);
}