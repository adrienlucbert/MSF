/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** obj
*/

#ifndef MSF_OBJ_H_
#define MSF_OBJ_H_

#include "msf.h"

/*
**  ENUMS
*/
enum msf_obj_type_e {
    text,
    animated,
    input,
    shape,
    sound,
    custom
};

enum msf_obj_fixing_e {
    fixed,
    absolute
};

/*
**  STRUCTS
*/

/*
**  Game Object Virtual Functions Table
**      render                  render object
**      set_origin              set object's transformations origin
**      set_position            set object position
**      set_size                set object size
**      set_scale               set object scale
**      set_fill_color          set object fill color
**      set_outline_color       set object outline color
**      set_outline_thickness   set object outline thickness
**      set_rotation            set object rotation
**      set_texture             set object texture
*/
struct msf_obj_vtable_s {
    void (*render)                  (void *, hub_t *);
    void (*set_origin)              (void *, sfVector2f);
    void (*set_position)            (void *, sfVector2f);
    void (*set_size)                (void *, sfVector2u);
    void (*set_radius)              (void *, float);
    void (*set_scale)               (void *, sfVector2f);
    void (*set_fill_color)          (void *, sfColor);
    void (*set_outline_color)       (void *, sfColor);
    void (*set_outline_thickness)   (void *, float);
    void (*set_rotation)            (void *, float);
    void (*set_texture)             (void *, sfTexture *, sfBool);
    sfVector2f (*get_origin)        (void *);
    sfVector2f (*get_position)      (void *);
    sfVector2u (*get_size)          (void *);
    float (*get_radius)             (void *);
    sfVector2f (*get_scale)         (void *);
    sfColor (*get_fill_color)       (void *);
    sfColor (*get_outline_color)    (void *);
    float (*get_outline_thickness)  (void *);
    float (*get_rotation)           (void *);
    const sfTexture *(*get_texture) (void *);
    sfFloatRect (*get_box)          (void *);
};


/*
** User data dtor
*/
struct msf_udata_s {
    void (*dtor)(void *);
};

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
**  Game Object Physics
**      angle           object's movement initial angle
**      gravity         value of the gravity applied to the object
**      restitution     value of the bounciness of the object
**      speed           speed of the game object
*/
struct msf_obj_physics_s {
    float angle;
    float gravity;
    float restitution;
    float mass;
    float inv_mass;
    sfVector2f speed;
    sfVector2f pos;
    sfVector2u size;
    sfVector2f scale;
    float radius;
};

/*
**  Game Object
**      fixing      how object moves with camera
**      type        type of the object
**      group       group of the object
**      state       whether object is dead or alive (to be rendered or not)
**      is_collider whether object must collide with other colliders or not
**      vtable      table of virtual functions for the object
**      physics     data for managing physics and collisions between objects
**      mouse_evt   data related to mouse events on the object
**      udata       optional data for whatever purpose needed by the project
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
    sfBool is_collider;
    obj_vtable_t *vtable;
    obj_physics_t *physics;
    obj_mouse_evt_t *mouse_evt;
    void *udata;
    void (*on_active)(hub_t *, void *);
    sfSound *sound;
    int nbr;
    sfBool is_alive;
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
    sfBool is_collider;
    obj_vtable_t *vtable;
    obj_physics_t *physics;
    obj_mouse_evt_t *mouse_evt;
    void *udata;
    void (*on_active)(hub_t *, void *);
    sfSound *sound;
    int nbr;
    sfBool is_alive;

    sfText *text;
    sfFont *font;
    char *str;
};

/*
**  Animated Game Object
**      anims       list of animations
**      sprite      object sprite for texture rendering
**      scale       object scale
**      origin      object transformation origin
**      timer       animation clock
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
    sfBool is_collider;
    obj_vtable_t *vtable;
    obj_physics_t *physics;
    obj_mouse_evt_t *mouse_evt;
    void *udata;
    void (*on_active)(hub_t *, void *);
    sfSound *sound;
    int nbr;
    sfBool is_alive;

    sfSprite *sprite;
    sfInt64 elapsed;
    void *anims;
};

/*
**  Animation
**      frame_duration  frame duration (in ms)
**      frames          list of animation's frames
*/
struct msf_anim_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    sfVector2f origin;
    uint frame_duration;
    void *frames;
    sfBool loop;
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
    int index;
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
    sfBool is_collider;
    obj_vtable_t *vtable;
    obj_physics_t *physics;
    obj_mouse_evt_t *mouse_evt;
    void *udata;
    void (*on_active)(hub_t *, void *);
    sfSound *sound;
    int nbr;
    sfBool is_alive;

    void *background;
    void *foreground;
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
    sfBool is_collider;
    obj_vtable_t *vtable;
    obj_physics_t *physics;
    obj_mouse_evt_t *mouse_evt;
    void *udata;
    void (*on_active)(hub_t *, void *);
    sfSound *sound;
    int nbr;
    sfBool is_alive;

    void *shape;
};


/*
**  Sound Game Object
*/
struct msf_sound_obj_s {
    // msf_node_s inherited properties
    char *label;
    void *next;
    void (*dtor)(void *);

    // msf_game_obj_s inherited properties
    obj_fixing fixing;
    obj_type type;
    int group;
    sfBool state;
    sfBool is_collider;
    obj_vtable_t *vtable;
    obj_physics_t *physics;
    obj_mouse_evt_t *mouse_evt;
    void *udata;
    void (*on_active)(hub_t *, void *);
    sfSound *sound;
    int nbr;
    sfBool is_alive;

    sfInt64 elapsed;
    sfInt64 repeat_delay;
    sfBool loop;
};

/*
**  PROTOTYPES
*/
// OBJ TOR
void *obj_new(obj_type type, sfBool is_collider);
void obj_ctor(void *obj, obj_type type, sfBool is_collider);
void obj_dtor(void *obj);
void obj_destroy(void *obj);

// OBJ MET
void obj_render(void *obj, hub_t *hub);
void obj_move(void *obj, hub_t *hub);
void obj_bounce(void *obj, float angle, float initial_speed);
sfBool obj_collide(hub_t *hub, void *obj_a, void *obj_b);
sfBool obj_apply_collision(hub_t *hub, void *obj_a, void *obj_b);
sfBool obj_collide_with_all(hub_t *hub, void *obj);
sfBool obj_apply_collision_with_all(hub_t *hub, void *obj);
sfBool obj_collide_with_group(hub_t *hub, void *obj, int group);
sfBool obj_apply_collision_with_group(hub_t *hub, void *obj, int group);
void obj_recenter_origin(void *obj);
void obj_kill(void *obj);

// OBJ SETTERS
void obj_set_group(void *obj, int group);
void obj_set_state(void *obj, sfBool state);
void obj_set_speed(void *obj, float sx, float sy);
void obj_set_pos(void *obj, float x, float y);
void obj_set_sound_buffer(hub_t *hub, void *obj, char *label);
void obj_set_volume(void *obj, float volume);
void objs_set_volume(void *obj, float volume);
void obj_sound_apply(obj_t *obj, void (*func)(sfSound *));
void objs_sound_apply(obj_t *obj, void (*func)(sfSound *));

// OBJ MOUSE EVT TOR
void *obj_mouse_evt_new(void);
void obj_mouse_evt_ctor(void *mouse_evt);
void obj_mouse_evt_destroy(void *mouse_evt);

// OBJ PHYSICS TOR
void *physics_new(void *obj);
void physics_ctor(void *physics, void *obj);
void physics_destroy(void *physics);

// OBJ PHYSICS MET
void physics_reset(void *physics);
void physics_repulse(manifold_t *m);

// OBJ PHYSICS SET
void obj_physics_set_gravity(void *obj, float gravity);
void obj_physics_set_restitution(void *obj, float restitution);
void obj_physics_set_angle(void *obj, float angle);

// MANIFOLD TOR
void *manifold_new(void *phy_a, obj_physics_t *phy_b);
void manifold_ctor(void *manifold, obj_physics_t *phy_a, obj_physics_t *phy_b);
void manifold_destroy(void *manifold);

// MANIFOLD MET
void manifold_reset(manifold_t *m, obj_physics_t *phy_a, obj_physics_t *phy_b);
sfBool manifold_collide(manifold_t *m);
sfBool aabb_aabb_collision(manifold_t *m);
sfBool circle_circle_collision(manifold_t *m);
sfBool aabb_circle_collision(manifold_t *m, sfBool aabb_first);

// TEXT TOR
void *text_obj_new(char *str, sfColor color, uint char_size);
void text_obj_ctor(void *text_obj, char *str, sfColor color, uint char_size);
void text_obj_dtor(void *text_obj);
void text_obj_destroy(void *text_obj);

// TEXT MET
void text_obj_render(void *text_obj, hub_t *hub);

// TEXT SET
void text_obj_set_font(void *text_obj, char *fontpath);
void text_obj_set_color(void *text_obj, sfColor color);
void text_obj_set_char_size(void *text_obj, uint char_size);
void text_obj_set_string(void *text_obj, char *str);
void text_obj_set_origin(void *text_obj, sfVector2f origin);
void text_obj_set_position(void *text_obj, sfVector2f position);
void text_obj_set_rotation(void *text_obj, float angle);
void text_obj_set_scale(void *text_obj, sfVector2f scale);
void text_obj_set_size(void *text_obj, sfVector2u size);
void text_obj_set_fill_color(void *text_obj, sfColor color);
void text_obj_set_outline_color(void *text_obj, sfColor color);
void text_obj_set_outline_thickness(void *text_obj, float thickness);

// TEXT GET
sfVector2f text_obj_get_origin(void *text_obj);
sfVector2f text_obj_get_position(void *text_obj);
float text_obj_get_rotation(void *text_obj);
sfVector2f text_obj_get_scale(void *text_obj);
sfVector2u text_obj_get_size(void *text_obj);
sfFloatRect text_obj_get_box(void *text);
sfColor text_obj_get_fill_color(void *text_obj);
sfColor text_obj_get_outline_color(void *text_obj);
float text_obj_get_outline_thickness(void *text_obj);

// TEXT VTABLE
void *text_obj_vtable_new(void);
void text_obj_vtable_ctor_met(void *obj_vtable);
void text_obj_vtable_ctor_set(void *obj_vtable);
void text_obj_vtable_ctor_get(void *obj_vtable);
void text_vtable_destroy(void *obj_vtable);

// ANIMATED TOR
void *anim_obj_new(void);
void anim_obj_ctor(void *anim_obj);
void anim_obj_dtor(void *anim_obj);
void anim_obj_destroy(void *anim_obj);

// ANIMATED MET
void anim_obj_add_anim(void *obj, void *anim, char *label);
void anim_obj_render(void *anim_obj, hub_t *hub);

// ANIMATED SET
void anim_obj_set_origin(void *anim_obj, sfVector2f origin);
void anim_obj_set_position(void *anim_obj, sfVector2f position);
void anim_obj_set_rotation(void *anim_obj, float rotation);
void anim_obj_set_scale(void *anim_obj, sfVector2f scale);
void anim_obj_set_size(void *anim_obj, sfVector2u size);
void anim_obj_set_texture(void *anim_obj, sfTexture *texture, sfBool reset);

// ANIMATED GET
sfVector2f anim_obj_get_origin(void *anim_obj);
sfVector2f anim_obj_get_position(void *anim_obj);
float anim_obj_get_rotation(void *anim_obj);
sfVector2f anim_obj_get_scale(void *anim_obj);
sfVector2u anim_obj_get_size(void *anim_obj);
const sfTexture *anim_obj_get_texture(void *anim_obj);
sfFloatRect anim_obj_get_box(void *anim_obj);

// ANIMATED VTABLE
void *anim_obj_vtable_new(void);
void anim_obj_vtable_ctor_met(void *obj_vtable);
void anim_obj_vtable_ctor_set(void *obj_vtable);
void anim_obj_vtable_ctor_get(void *obj_vtable);
void anim_vtable_destroy(void *obj_vtable);

// ANIM TOR
void *anim_new(hub_t *hub, char *image, int nb_frames);
void anim_ctor(void *anim, hub_t *hub, char *image, int nb_frames);
void anim_dtor(void *anim);
void anim_destroy(void *anim);

// ANIM MET
void anim_add_frame(void *anim, void *frame, char *label);
void anim_set_loop(void *anim, sfBool loop);
void anim_reset_loop(void *anim);

// ANIM SET
void anim_set_frame_duration(void *anim, uint duration);
void anim_set_frames(void *anim, hub_t *hub, char *image, int nb_frames);

// FRAME TOR
void *frame_new(sfTexture *texture, int frm_index);
void frame_ctor(void *frame, sfTexture *texture, int frm_index);
void frame_dtor(void *frame);
void frame_destroy(void *frame);

// INPUT TOR
void *input_obj_new(void *background, void *foreground, sfVector2f pos);
void input_obj_ctor(void *input_obj, void *bck, void *frg, sfVector2f pos);
void input_obj_dtor(void *input_obj);
void input_obj_destroy(void *input_obj);

// INPUT MET
void input_obj_render(void *input_obj, hub_t *hub);
void input_obj_recenter(void *input_obj);
void input_obj_auto_scale_fg(input_obj_t *st_input);

// INPUT SET
void input_obj_set_activity(void *inpt_obj, void (*on_active)(hub_t *, void *));
void input_set_origin(void *input, sfVector2f origin);
void input_set_position(void *input, sfVector2f position);
void input_set_rotation(void *input, float rotation);
void input_set_scale(void *input, sfVector2f scale);
void input_set_size(void *input, sfVector2u size);

// INPUT GET
sfFloatRect input_obj_get_box(void *input_obj);

// INPUT VTABLE
void *input_obj_vtable_new(void);
void input_obj_vtable_ctor_met(void *obj_vtable);
void input_obj_vtable_ctor_set(void *obj_vtable);
void input_obj_vtable_ctor_get(void *obj_vtable);
void input_vtable_destroy(void *obj_vtable);

// CIRCLE TOR
void *circle_new(float radius, size_t point_count, sfColor color);
void circle_ctor(void *circle, float radius, size_t point_count, sfColor color);
void circle_dtor(void *obj);
void circle_destroy(void *obj);

// CIRCLE MET
void circle_render(void *circle, hub_t *hub);

// CIRCLE SET
void circle_set_origin(void *circle, sfVector2f origin);
void circle_set_position(void *circle, sfVector2f position);
void circle_set_rotation(void *circle, float rotation);
void circle_set_scale(void *circle, sfVector2f scale);
void circle_set_size(void *circle, sfVector2u size);
void circle_set_outline_color(void *circle, sfColor outline);
void circle_set_fill_color(void *circle, sfColor fill);
void circle_set_outline_thickness(void *circle, float thickness);
void circle_set_texture(void *circle, sfTexture *texture, sfBool reset);
void circle_set_radius(void *circle, float radius);
void circle_set_point_count(void *circle, int point_count);

// CIRCLE GET
sfVector2f circle_get_origin(void *circle);
sfVector2f circle_get_position(void *circle);
float circle_get_rotation(void *circle);
sfVector2f circle_get_scale(void *circle);
sfVector2u circle_get_size(void *circle);
sfFloatRect circle_get_box(void *circle);
sfColor circle_get_outline_color(void *circle);
sfColor circle_get_fill_color(void *circle);
float circle_get_outline_thickness(void *circle);
const sfTexture *circle_get_texture(void *circle);
float circle_get_radius(void *circle);
size_t circle_get_point_count(void *circle);

// CIRCLE VTABLE
void *circle_vtable_new(void);
void circle_vtable_ctor_met(void *obj_vtable);
void circle_vtable_ctor_set(void *obj_vtable);
void circle_vtable_ctor_get(void *obj_vtable);
void circle_vtable_destroy(void *obj_vtable);

// RECT TOR
void *rect_new(sfVector2u size, sfColor color);
void rect_ctor(void *rect, sfVector2u size, sfColor color);
void rect_dtor(void *rect);
void rect_destroy(void *shape_obj);

// RECT MET
void rect_render(void *shape_obj, hub_t *hub);

// CIRCLE SET
void rect_set_origin(void *rect, sfVector2f origin);
void rect_set_position(void *rect, sfVector2f position);
void rect_set_rotation(void *rect, float rotation);
void rect_set_scale(void *rect, sfVector2f scale);
void rect_set_size(void *rect, sfVector2u size);
void rect_set_outline_color(void *rect, sfColor outline);
void rect_set_fill_color(void *rect, sfColor fill);
void rect_set_outline_thickness(void *rect, float thickness);
void rect_set_texture(void *rect, sfTexture *texture, sfBool reset);

// CIRCLE GET
sfVector2f rect_get_origin(void *rect);
sfVector2f rect_get_position(void *rect);
float rect_get_rotation(void *rect);
sfVector2f rect_get_scale(void *rect);
sfVector2u rect_get_size(void *rect);
sfFloatRect rect_get_box(void *rect);
sfColor rect_get_outline_color(void *rect);
sfColor rect_get_fill_color(void *rect);
float rect_get_outline_thickness(void *rect);
const sfTexture *rect_get_texture(void *rect);

// RECT VTABLE
void *rect_vtable_new(void);
void rect_vtable_ctor_met(void *obj_vtable);
void rect_vtable_ctor_set(void *obj_vtable);
void rect_vtable_ctor_get(void *obj_vtable);
void rect_vtable_destroy(void *obj_vtable);

// SOUND_OBJ TOR
void *sound_obj_new(hub_t *hub, char *buffer);
void sound_obj_ctor(void *obj, hub_t *hub, char *buffer);
void sound_obj_destroy(void *shape_obj);

// SOUND_OBJ MET
void sound_obj_render(void *sound, hub_t *hub);

// SOUND_OBJ SET
void sound_obj_set_loop(void *sound, sfBool loop, sfInt64 delay);

// SOUND_OBJ GET
sfSoundStatus sound_obj_get_status(void *sound);
sfBool sound_obj_get_loop(void *sound);

// SOUND_OBJ VTABLE
void *sound_obj_vtable_new(void);
void sound_obj_vtable_ctor_met(void *obj_vtable);
void sound_obj_vtable_ctor_set(void *obj_vtable);
void sound_obj_vtable_ctor_get(void *obj_vtable);
void sound_obj_vtable_destroy(void *obj_vtable);

#endif /* !MSF_OBJ_H_ */