/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** image_tor
*/

#include "msf/msf.h"

void *image_new(char *path)
{
    image_t *st_image = NULL;

    FAIL_IF(!path, NULL);
    st_image = malloc(sizeof(image_t));
    FAIL_IF(!st_image, NULL);
    image_ctor(st_image, path);
    if (!st_image->sheet) {
        free(st_image);
        return (NULL);
    }
    return ((void *)st_image);
}

void image_ctor(void *image, char *path)
{
    image_t *st_image = (image_t *)image;

    FAIL_IF_VOID(!st_image);
    st_image->label = NULL;
    st_image->next = NULL;
    st_image->sheet = NULL;
    st_image->sheet = sfImage_createFromFile(path);
    st_image->dtor = image_dtor;
}

void image_dtor(void *image)
{
    image_t *st_image = (image_t *)image;

    if (st_image->sheet)
        sfImage_destroy(st_image->sheet);
    if (st_image->label)
        free(st_image->label);
}

void image_destroy(void *image)
{
    image_dtor(image);
    free(image);
}