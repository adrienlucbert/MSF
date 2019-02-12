/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_strtok
*/

#include "my.h"
#include <stdio.h>

int count_substr(char *str, char const *delim);

char **my_strtok(char *str, char const *delim)
{
    char **arr = my_calloc(count_substr(str, delim) + 1, sizeof(char *));
    int str_len = my_memlen(str, sizeof(char));
    int delim_len = my_memlen(delim, sizeof(char));
    char *ptr = str;
    char *token = my_strstr(str, delim);
    int index = 0;

    while (token) {
        if (token != str && token != ptr) {
            arr[index++] = my_memdup(ptr, token - ptr);
            ptr = token;
        }
        while (*ptr && ptr - token < delim_len)
            ++ptr;
        token = ptr;
        token = my_strstr(ptr, delim);
    }
    if (*ptr != '\0')
        arr[index++] = my_memdup(ptr, str + str_len - ptr);
    return (arr);
}

int count_substr(char *str, char const *delim)
{
    int str_len = my_memlen(str, sizeof(char));
    int delim_len = my_memlen(delim, sizeof(char));
    char *ptr = str;
    char *token = my_strstr(str, delim);
    int count = 0;

    while (token) {
        if (token != str && token != ptr) {
            ++count;
            ptr = token;
        }
        while (*ptr && ptr - token < delim_len)
            ++ptr;
        token = ptr;
        token = my_strstr(ptr, delim);
    }
    if (*ptr != '\0')
        ++count;
    return (count);
}