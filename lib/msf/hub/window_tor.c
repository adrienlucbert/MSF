/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** window
*/

#include "msf/msf.h"

sfRenderWindow *window_new(char *title, sfVector2i size, sfUint32 style)
{
    sfVideoMode mode = {size.x, size.y, 32};
    sfRenderWindow *window = NULL;

    window = sfRenderWindow_create(mode, title, style, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}

void window_destroy(sfRenderWindow *window)
{
    if (window)
        sfRenderWindow_destroy(window);
}