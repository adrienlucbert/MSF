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
typedef struct msf_text_obj_s       text_obj_t;
typedef struct msf_animated_obj_s   anim_obj_t;
typedef struct msf_input_obj_s      input_obj_t;
typedef struct msf_shape_obj_s      shape_obj_t;
typedef struct msf_obj_mouse_evt_s  obj_mouse_evt_t;
typedef struct msf_node_s           node_t;
typedef struct msf_frame_s          frame_t;
typedef enum msf_obj_type_e         obj_type;
typedef enum msf_obj_fixing_e       obj_fixing;
typedef enum msf_evt_scope_e        evt_scope;
typedef enum msf_shape_e            obj_shape;
typedef unsigned int                uint;

#endif /* !MSF_TYPES_H_ */