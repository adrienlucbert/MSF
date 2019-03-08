/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_realloc
*/

#include "my.h"
#include <stdlib.h>

void *my_realloc(void *ptr, size_t size)
{
    void *dest = malloc(size);

    my_memset(dest, 0, size);
    if (dest)
        my_memcpy(dest, ptr, size);
    free(ptr);
    return (dest);
}