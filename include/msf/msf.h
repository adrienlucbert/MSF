/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** msf
*/

#ifndef MSF_H_
#define MSF_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Network.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "msf/evt.h"
#include "msf/hub.h"
#include "msf/scene.h"
#include "msf/ll.h"
#include "msf/macro.h"
#include "msf/obj.h"
#include "msf/types.h"
#include "msf/sound.h"
#include "my.h"

/*
**  UTILS
*/
sfVector2f vector_rotate(sfVector2f u0, float angle);
sfVector2f vector_add(sfVector2f v0, sfVector2f v1);
sfVector2f vector_sub(sfVector2f v0, sfVector2f v1);
sfVector2f vector_mul(sfVector2f v0, sfVector2f v1);
float vector_magnitude(sfVector2f v);
sfVector2f vector_normalize(sfVector2f v0);

#endif /* !MSF_H_ */