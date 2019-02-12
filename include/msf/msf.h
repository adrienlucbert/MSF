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
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <time.h>
#include "msf/evt.h"
#include "msf/hub.h"
#include "msf/scene.h"
#include "msf/ll.h"
#include "msf/macro.h"
#include "msf/obj.h"
#include "msf/types.h"
#include "my.h"

sfVector2f vectorf_new(float x, float y);
sfVector2i vectori_new(int x, int y);
sfVector2u vectoru_new(uint x, uint y);

#endif /* !MSF_H_ */