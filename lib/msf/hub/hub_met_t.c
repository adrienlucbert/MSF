/*
** EPITECH PROJECT, 2019
** msf
** File description:
** hub_met_t
*/

#include "msf/msf.h"

sfBool hub_load_image(hub_t *hub, char *path, char *label)
{
    image_t *img = NULL;

    FAIL_IF(!hub || !path, sfFalse);
    img = image_new(path);
    FAIL_IF(!img, sfFalse);
    hub_add_image(hub, img, label);
    return (sfTrue);
}

sfBool hub_load_buffer(hub_t *hub, char *path, char *label)
{
    sound_buffer_t *buffer = NULL;

    FAIL_IF(!hub || !path, sfFalse);
    buffer = sound_buffer_new(path);
    FAIL_IF(!buffer, sfFalse);
    hub_add_buffer(hub, buffer, label);
    return (sfTrue);
}

void hub_add_image(hub_t *hub, image_t *image, char *label)
{
    FAIL_IF_VOID(!hub || !image);
    image->label = my_memdup(label, -1);
    list_append((void **)(&hub->images), image);
}

void hub_add_buffer(void *hub, void *buffer, char *label)
{
    hub_t *st_hub = (hub_t *)hub;

    FAIL_IF_VOID(!st_hub || !buffer);
    node_ctor(buffer, label, NULL);
    list_append((void *)(&st_hub->sound_buffers), buffer);
}