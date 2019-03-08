/*
** EPITECH PROJECT, 2018
** Libmy
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

int my_atoi(char const *str);
void my_putnbr(int nb);
char *my_itoa(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
void *my_calloc(size_t nmemb, size_t size);
void *my_memset(void *s, int c, size_t n);
void *my_realloc(void *ptr, size_t size);
void *my_memcpy(void *dest, const void *src, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);
int my_memlen(void const *ptr, size_t size);
void *my_memdup(const void *src, size_t n);
void *my_memcat(void *dest, void const *src);
void *my_memchr(const void *s, int c, size_t n);
void *my_memmem(void const *hay, size_t h_len, void const *nee, size_t n_len);
int my_perror(char *msg, int n_suff, ...);
char *my_format(char const *format, ...);

#endif /* !MY_H_ */