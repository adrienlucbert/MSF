/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** window
*/

#include "msf/msf.h"

void window_set_icon(sfRenderWindow *window, char *path)
{
    sfImage *img = sfImage_createFromFile(path);
    const sfUint8 *icon = sfImage_getPixelsPtr(img);

    sfRenderWindow_setIcon(window, 256, 256, icon);
    sfImage_destroy(img);
}