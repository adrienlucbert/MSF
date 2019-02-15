/*
** EPITECH PROJECT, 2019
** MSF
** File description:
** scene_set
*/

#include "msf/msf.h"

void scene_set_cam_speed(void *scene, float sx, float sy)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene);
    st_scene->cam_speed.x = sx;
    st_scene->cam_speed.y = sy;
}

void scene_set_cam_pos(void *scene, float x, float y)
{
    scene_t *st_scene = (scene_t *)scene;

    FAIL_IF_VOID(!st_scene);
    st_scene->cam_pos.x = x;
    st_scene->cam_pos.y = y;
}