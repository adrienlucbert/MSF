/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_perror
*/

#include "my.h"

int my_perror(char *msg, int n_suff, ...)
{
    va_list ap;
    char *str = NULL;
    int index = 0;

    va_start(ap, n_suff);
    write(2, msg, my_memlen(msg, sizeof(char)));
    str = va_arg(ap, char *);
    while (index < n_suff) {
        write(2, ": ", 2);
        write(2, str, my_memlen(str, sizeof(char)));
        ++index;
        if (index < n_suff)
            str = va_arg(ap, char *);
    }
    write(2, "\n", 1);
    va_end(ap);
    return (1);
}