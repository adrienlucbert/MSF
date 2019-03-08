/*
** EPITECH PROJECT, 2019
** def_upd
** File description:
** my_format
*/

#include "my.h"

int concat_data(char **str, char spec, va_list ap);

int concat_s(char **str, va_list ap);

int concat_di(char **str, va_list ap);

int concat_c(char **str, va_list ap);

char *my_format(char const *format, ...)
{
    int index = 0;
    int size = 0;
    char *str = NULL;

    va_list ap;
    va_start(ap, format);
    while (format[index]) {
        if (format[index] == '%' && format[index + 1] != '\0') {
            size += concat_data(&str, format[index + 1], ap);
            ++index;
        } else {
            str = my_realloc(str, size + 2);
            str[size] = format[index];
            ++size;
        }
        ++index;
    }
    va_end(ap);
    return (str);
}

int concat_data(char **str, char spec, va_list ap)
{
    int len = my_memlen(*str, sizeof(char));
    char *flags = "sdic";
    int index = -1;
    int (*concat_fns[4])(char **, va_list ap);

    concat_fns[0] = concat_s;
    concat_fns[1] = concat_di;
    concat_fns[2] = concat_di;
    concat_fns[3] = concat_c;
    if (my_memchr("sdic", spec, -1)) {
        index = (char *)my_memchr(flags, spec, -1) - flags;
        return (concat_fns[index](str, ap));
    } else {
        *str = my_realloc(str, len + 2);
        *str[len] = '%';
        *str[len + 1] = spec;
        return (2);
    }
}

int concat_s(char **str, va_list ap)
{
    char *arg = va_arg(ap, char *);
    int arg_len = 0;

    if (!arg)
        return (0);
    arg_len = my_memlen(arg, sizeof(char));
    *str = my_memcat(*str, arg);
    return (arg_len);
}

int concat_di(char **str, va_list ap)
{
    char *arg = my_itoa(va_arg(ap, int));
    int arg_len = 0;

    if (!arg)
        return (0);
    arg_len = my_memlen(arg, sizeof(char));
    *str = my_memcat(*str, arg);
    return (arg_len);
}

int concat_c(char **str, va_list ap)
{
    char arg = va_arg(ap, int);
    int str_len = 0;

    if (!arg)
        return (0);
    str_len = my_memlen(*str, sizeof(char));
    *str = my_realloc(*str, str_len + 2);
    (*str)[str_len] = arg;
    return (1);
}