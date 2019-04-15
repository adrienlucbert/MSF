/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** types
*/

#ifndef MSF_TYPES_H_
#define MSF_TYPES_H_

typedef struct msf_hub_s            hub_t;
typedef struct msf_scene_s          scene_t;
typedef struct msf_game_evt_s       evt_t;
typedef struct msf_game_obj_s       obj_t;
typedef struct msf_obj_container_s  obj_container_t;
typedef struct msf_text_obj_s       text_obj_t;
typedef struct msf_animated_obj_s   anim_obj_t;
typedef struct msf_input_obj_s      input_obj_t;
typedef struct msf_shape_obj_s      shape_obj_t;
typedef struct msf_obj_mouse_evt_s  obj_mouse_evt_t;
typedef struct msf_obj_vtable_s     obj_vtable_t;
typedef struct msf_obj_physics_s    obj_physics_t;
typedef struct msf_sound_obj_s      sound_obj_t;
typedef struct msf_manifold_s       manifold_t;
typedef struct msf_anim_s           anim_t;
typedef struct msf_node_s           node_t;
typedef struct msf_frame_s          frame_t;
typedef struct msf_image_s          image_t;
typedef struct msf_sound_buffer_s   sound_buffer_t;
typedef struct msf_sound_s          sound_t;
typedef struct msf_udata_s           udata_t;
typedef enum msf_obj_type_e         obj_type;
typedef enum msf_obj_fixing_e       obj_fixing;
typedef enum msf_evt_scope_e        evt_scope;
typedef enum msf_shape_e            obj_shape;
typedef unsigned int                uint;

#endif /* !MSF_TYPES_H_ */