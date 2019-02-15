/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** anim_set
*/

#include "msf/msf.h"

void anim_set_frames(void *anim, char *filepath, int nb_frames)
{
    sfImage *sheet = sfImage_createFromFile(filepath);
    sfVector2u size = sfImage_getSize(sheet);
    sfIntRect area = {0, 0, size.x / nb_frames, size.y};
    sfTexture *texture = NULL;
    int frame_id = 0;

    while (frame_id < nb_frames) {
        texture = sfTexture_createFromImage(sheet, &area);
        anim_add_frame(anim, frame_new(texture), NULL);
        area.left += size.x / nb_frames;
        ++frame_id;
    }
    sfSprite_setTexture(((anim_t *)anim)->sprite, texture, sfTrue);
}