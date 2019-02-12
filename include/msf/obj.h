/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** obj
*/

#ifndef MSF_OBJ_H_
#define MSF_OBJ_H_

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <time.h>
#include "msf/types.h"

/*
**  ENUMS
*/
enum msf_obj_type_e {
    text,
    animated,
    input
};

enum msf_obj_fixing_e {
    fixed,
    absolute
};

/*
**  TYPES
*/
typedef void (*obj_render_method)(hub_t *, void *);

/*
**  STRUCTS
*/

/*
**  Game Object Mouse Event
**      focus       is object focused (last clicked object)
**      hover       is object hovered (mouse over object)
**      active      is object active (mouse button held down over object)
**      x           x coordinate of mouse
**      y           y coordinate of mouse
*/
struct msf_obj_mouse_evt_s {
    sfBool focus;
    sfBool hover;
    sfBool active;
    int x;
    int y;
};

/*
**  Game Object
**      fixing      how object moves with camera
**      type        type of the object
**      group       group of the object
**      state       whether object is dead or alive (to be rendered or not)
**      speed       move speed of the object
**      pos         position of the object in the scene
**      rotation    rotation angle of the object
**      display     display function for the object (depending on its type)
*/
struct msf_game_obj_s {
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    float rotation;
    obj_render_method render;
    obj_mouse_evt_t mouse_evt;

    // msf_node_s inherited properties
    char *label;
    void *data;
    void *next;
    void (*dtor)(void *node);
};

/*
**  Text Game Object
**      text        SFML text structure
**      font        font of the text
**      color       color of the text
**      char_size   size of a character
**      str         string to be written
*/
struct msf_text_obj_s {
    sfText *text;
    sfFont *font;
    sfColor color;
    uint char_size;
    char *str;

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    float rotation;
    obj_render_method render;
    obj_mouse_evt_t mouse_evt;

    // msf_node_s inherited properties
    char *label;
    void *next;
};

/*
**  Animated Game Object
**      anims       list of animations
*/
struct msf_animated_obj_s {
    void *anims;

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    float rotation;
    obj_render_method render;
    obj_mouse_evt_t mouse_evt;

    // msf_node_s inherited properties
    char *label;
    void *next;
};

/*
**  Animation
**      sprite          object sprite for texture rendering
**      scale           object scale
**      origin          object transformation origin
**      frame_duration  frame duration (in ms)
**      timer           animation clock
**      frames          list of animation's frames
*/
struct msf_anim_s {
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f origin;
    uint frame_duration;
    sfClock *timer;
    void *frames;

    // msf_node_s inherited properties
    char *label;
    void *next;
};

/*
**  Input Game Object
**      value       input value
*/
struct msf_input_obj_s {
    void *value;

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    float rotation;
    obj_render_method render;
    obj_mouse_evt_t mouse_evt;

    // msf_node_s inherited properties
    char *label;
    void *next;
};

/*
**  PROTOTYPES
*/
// OBJ TOR
void *obj_new(obj_type type);
void *obj_ctor(void *obj, obj_type type);
void obj_dtor(void *obj);
void obj_destroy(void *obj);

// TEXT TOR

// TEXT MET
void obj_text_render(hub_t *hub, void *obj);

// ANIMATED TOR

// ANIMATED MET
void obj_animated_render(hub_t *hub, void *obj);

// INPUT TOR

// INPUT MET
void obj_input_render(hub_t *hub, void *obj);

#endif /* !MSF_OBJ_H_ */