/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** hub
*/

#ifndef MSF_HUB_H_
#define MSF_HUB_H_

/*
**  STRUCTS
*/

/*
**  Object Collision Manifold
**      phy_a           physics of A object
**      phy_b           physics of B object
**      penetration     penetration of object A into object B (if they collide)
**      normal          objects collision normal vector
*/
struct msf_manifold_s {
    obj_physics_t *phy_a;
    obj_physics_t *phy_b;
    float penetration;
    sfVector2f normal;
};

/*
**  Game Hub
**      window       game window
**      global_evts  list of non scene-dependent events
**      framerate    game framerate (in frames per second)
**      timer        hub timer to handle framerate
**      scenes       list of scenes of the game
**      manifold     list of scenes of the game
*/
struct msf_hub_s {
    sfRenderWindow *window;
    void *global_evts;
    uint framerate;
    sfClock *timer;
    void *scenes;
    manifold_t *manifold;
    sound_buffer_t *sound_buffers;
};

/*
**  PROTOTYPES
*/
// HUB CTOR
void *hub_new(char *title, sfVector2i size, sfUint32 style);
void hub_ctor(void *hub, char *title, sfVector2i size, sfUint32 style);
void hub_dtor(void *hub);
void hub_destroy(void *hub);

// HUB MET
void hub_add_global_evt(void *hub, void *global_evt, char *label);
void hub_add_scene(void *hub, void *scene, char *label);
void hub_render(hub_t *hub);
void hub_trigger_evts_scope(hub_t *hub, evt_scope scope, sfEvent data);
void hub_add_buffer(void *hub, void *buffer, char *label);

// GLOBAL EVTS
void window_close_evt(hub_t *hub, sfEvent evt);
void mouse_evt_updater_evt(hub_t *hub, sfEvent evt);

// HUB SETTERS
void hub_set_framerate(void *hub, uint framerate);

// WINDOW CTOR
sfRenderWindow *window_new(char *title, sfVector2i size, sfUint32 style);
void window_destroy(sfRenderWindow *window);

// WINDOW MET
void window_render(hub_t *hub);

#endif /* !MSF_HUB_H_ */