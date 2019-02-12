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
    void *objs;
    void *evts;
    sfVector2f cam_speed;
    sfVector2f cam_pos;

    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);
};

/*
**  PROTOTYPES
*/
// SCENE TOR
void *scene_new(void);
void *scene_ctor(void *scene);
void scene_dtor(void *scene);
void scene_destroy(void *scene);

// SCENE MET
void scene_add_evt(void *scene, void *evt, char *label);
void scene_add_obj(void *scene, void *obj, char *label);

#endif /* !SCENE_H_ */