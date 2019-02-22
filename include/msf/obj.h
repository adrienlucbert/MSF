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
    input,
    shape
};

enum msf_obj_fixing_e {
    fixed,
    absolute
};

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
**      display     display function for the object (depending on its type)
*/
struct msf_game_obj_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    void (*render)(hub_t *, void *);
    obj_mouse_evt_t *mouse_evt;
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
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    void (*render)(hub_t *, void *);
    obj_mouse_evt_t *mouse_evt;

    sfText *text;
    sfFont *font;
    sfColor color;
    uint char_size;
    char *str;
};

/*
**  Animated Game Object
**      anims       list of animations
*/
struct msf_animated_obj_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    void (*render)(hub_t *, void *);
    obj_mouse_evt_t *mouse_evt;

    void *anims;
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
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f origin;
    float rotation;
    uint frame_duration;
    sfClock *timer;
    void *frames;
};

/*
**  Frame
**      texture         texture of the frame
*/
struct msf_frame_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    sfTexture *texture;
};

/*
**  Input Game Object
**      value       input value
*/
struct msf_input_obj_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    void (*render)(hub_t *, void *);
    obj_mouse_evt_t *mouse_evt;

    void *value;
};

/*
**  Shape Game Object
**      value       shape value
*/
struct msf_shape_obj_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfVector2f speed;
    sfVector2f pos;
    void (*render)(hub_t *, void *);
    obj_mouse_evt_t *mouse_evt;

    void *shape;
    sfVector2f size;
    float radius;
    float outline_thickness;
    size_t point_count;
    sfColor outline_color;
    sfColor fill_color;
};

/*
**  PROTOTYPES
*/
// OBJ TOR
void *obj_new(obj_type type);
void obj_ctor(void *obj, obj_type type);
void obj_dtor(void *obj);
void obj_destroy(void *obj);

// OBJ MET
void obj_render(void *obj, void *hub);

// OBJ SETTERS
void obj_set_group(void *obj, int group);
void obj_set_state(void *obj, sfBool state);
void obj_set_speed(void *obj, float sx, float sy);
void obj_set_pos(void *obj, float x, float y);

// OBJ MOUSE EVT TOR
void *obj_mouse_evt_new(void);
void obj_mouse_evt_ctor(void *mouse_evt);
void obj_mouse_evt_destroy(void *mouse_evt);

// TEXT TOR
void *text_obj_new(char *str);
void text_obj_ctor(void *text_obj, char *str);
void text_obj_dtor(void *text_obj);
void text_obj_destroy(void *text_obj);

// TEXT MET
void text_obj_render(hub_t *hub, void *text_obj);

// TEXT SETTERS
void text_obj_set_font(void *text_obj, char *fontpath);
void text_obj_set_color(void *text_obj, sfColor color);
void text_obj_set_char_size(void *text_obj, uint char_size);
void text_obj_set_string(void *text_obj, char *str);

// ANIMATED TOR
void *anim_obj_new(void);
void anim_obj_ctor(void *anim_obj);
void anim_obj_dtor(void *anim_obj);
void anim_obj_destroy(void *anim_obj);

// ANIMATED MET
void anim_obj_add_anim(void *obj, void *anim, char *label);
void anim_obj_render(hub_t *hub, void *anim_obj);

// ANIM TOR
void *anim_new(char *filepath, int nb_frames, uint frame_duration);
void anim_ctor(void *anim, char *filepath, int nb_frames, uint frame_duration);
void anim_dtor(void *anim);
void anim_destroy(void *anim);

// ANIM MET
void anim_add_frame(void *anim, void *frame, char *label);

// ANIM SETTERS
void anim_set_frames(void *anim, char *filepath, int nb_frames);

// FRAME TOR
void *frame_new(sfTexture *texture);
void frame_ctor(void *frame, sfTexture *texture);
void frame_dtor(void *frame);
void frame_destroy(void *frame);

// INPUT TOR
void *input_obj_new(void);
void input_obj_ctor(void *input_obj);
void input_obj_dtor(void *input_obj);
void input_obj_destroy(void *input_obj);

// INPUT MET
void input_obj_render(hub_t *hub, void *input_obj);

// INPUT SET
void input_obj_set_value(void *input_obj, void *value);

// CIRCLE TOR
void *circle_new(float radius, size_t point_count, sfColor color);
void circle_ctor(void *circle, float radius, size_t point_count, sfColor color);
void circle_dtor(void *obj);
void circle_destroy(void *obj);

// CIRCLE MET
void circle_render(hub_t *hub, void *circle);

// CIRCLE SET
void circle_set_point_count(void *circle, int point_count);
void circle_set_fill_color(void *circle, sfColor fill);
void circle_set_outline_thickness(void *circle, float thickness);
void circle_set_radius(void *circle, float radius);
void circle_set_outline_color(void *circle, sfColor outline);
void circle_set_scale(void *rect, float scale_x, float scale_y);

// RECT TOR
void *rect_new(sfVector2f size, sfColor color);
void rect_ctor(void *rect, sfVector2f size, sfColor color);
void rect_dtor(void *rect);
void rect_destroy(void *shape_obj);

// RECT MET
void rect_render(hub_t *hub, void *shape_obj);

// RECT SET
void rect_set_scale(void *rect, float scale_x, float scale_y);
void rect_set_size(void *rect, float x, float y);
void rect_set_outline_thickness(void *rect, float thickness);
void rect_set_fill_color(void *rect, sfColor fill);
void rect_set_outline_color(void *rect, sfColor outline);

#endif /* !MSF_OBJ_H_ */