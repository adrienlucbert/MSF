/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_calloc
*/

#include "my.h"

void *my_calloc(size_t nmemb, size_t size)
{
    void *tmp = malloc(nmemb * size);

    if (tmp)
        my_memset(tmp, 0, nmemb * size);
    return (tmp);
}