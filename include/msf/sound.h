/*
** EPITECH PROJECT, 2019
** msf
** File description:
** sound.h
*/

#include "msf.h"

struct msf_sound_buffer_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    sfSoundBuffer *buffer;
};

// SOUND TOR
void *sound_buffer_new(char *path);
void sound_buffer_ctor(void *sound_buffer, char *path);
void sound_buffer_dtor(void *sound_buffer);
void sound_buffer_destroy(void *sound_buffer);

// SOUD SETTERS
void scenes_set_volume(void *scene, float volume);
void objs_set_volume(void *obj, float volume);
void obj_set_volume(void *obj, float volume);
void obj_set_sound_buffer(hub_t *hub, void *obj, char *label);
void scene_set_sound_buffer(hub_t *hub, void *scene, char *label);
void scene_sound_apply(scene_t *scene, void (*func)(sfSound *));