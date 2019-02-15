/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** scene
*/

#ifndef MSF_SCENE_H_
#define MSF_SCENE_H_

#include <SFML/System/Vector2.h>
#include "msf/types.h"

/*
**  STRUCTS
*/

/*
**  Game Scene
**      objs        list of objects in the scene
**      evts        list of events related to the scene
**      cam_speed   speed at which the scene camera moves
**      cam_pos     position of the scene camera
*/
struct msf_scene_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    void *objs;
    void *evts;
    sfVector2f cam_speed;
    sfVector2f cam_pos;
};

/*
**  PROTOTYPES
*/
// SCENE TOR
void *scene_new(void);
void scene_ctor(void *scene);
void scene_dtor(void *scene);
void scene_destroy(void *scene);

// SCENE MET
void scene_add_evt(void *scene, void *evt, char *label);
void scene_add_obj(void *scene, void *obj, char *label);

// SCENE SETTERS
void scene_set_cam_speed(void *scene, float sx, float sy);
void scene_set_cam_pos(void *scene, float x, float y);

#endif /* !SCENE_H_ */