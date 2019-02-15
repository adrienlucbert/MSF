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
**  Game Hub
**      window      game window
**      global_evts  list of non scene-dependent events
**      framerate   game framerate (in frames per second)
**      timer       hub timer to handle framerate
**      scenes       list of scenes of the game
*/
struct msf_hub_s {
    sfRenderWindow *window;
    void *global_evts;
    uint framerate;
    sfClock *timer;
    void *scenes;
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

// HUB SETTERS
void hub_set_framerate(void *hub, uint framerate);

// WINDOW CTOR
sfRenderWindow *window_new(char *title, sfVector2i size, sfUint32 style);
void window_destroy(sfRenderWindow *window);

// WINDOW MET
void window_render(hub_t *hub);

#endif /* !MSF_HUB_H_ */