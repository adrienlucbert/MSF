/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** frame_tor
*/

#include "msf/msf.h"

void *frame_new(sfTexture *texture, int frm_index)
{
    frame_t *st_frame = malloc(sizeof(frame_t));

    FAIL_IF(!st_frame, NULL);
    frame_ctor((void *)st_frame, texture, frm_index);
    return ((void *)st_frame);
}

void frame_ctor(void *frame, sfTexture *texture, int frm_index)
{
    frame_t *st_frame = (frame_t *)frame;

    FAIL_IF_VOID(!st_frame);
    st_frame->texture = texture;
    st_frame->index = frm_index;
    st_frame->dtor = frame_dtor;
}

void frame_dtor(void *frame)
{
    frame_t *st_frame = (frame_t *)frame;

    sfTexture_destroy(st_frame->texture);
}

void frame_destroy(void *frame)
{
    frame_dtor(frame);
    free(frame);
}