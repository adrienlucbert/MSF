/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** text_met
*/

#include "msf/msf.h"

void text_obj_render(void *text_obj, hub_t *hub)
{
    text_obj_t *st_text_obj = (text_obj_t *)text_obj;

    FAIL_IF_VOID(!st_text_obj || !hub);
    sfRenderWindow_drawText(hub->window, st_text_obj->text, NULL);
}