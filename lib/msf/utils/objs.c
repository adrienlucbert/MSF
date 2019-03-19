/*
** EPITECH PROJECT, 2019
** def_upd
** File description:
** objs
*/

#include "msf/msf.h"

sfVector2f objs_vector(obj_t *obj_a, obj_t *obj_b)
{
    sfVector2f v = {0, 0};
    sfFloatRect box_a = {0, 0, 0, 0};
    sfFloatRect box_b = {0, 0, 0, 0};

    FAIL_IF(!obj_a || !obj_b || !obj_a->physics || !obj_b->physics, v);
    FAIL_IF(!obj_a->vtable || !obj_a->vtable->get_box, v);
    FAIL_IF(!obj_b->vtable || !obj_b->vtable->get_box, v);
    box_a = VGET(obj_a, get_box);
    box_b = VGET(obj_b, get_box);
    v.x = (box_b.left + box_b.width / 2) - (box_a.left + box_a.width / 2);
    v.y = (box_b.top + box_b.height / 2) - (box_a.top + box_a.height / 2);
    return (v);
}

float objs_distance(obj_t *obj_a, obj_t *obj_b)
{
    sfVector2f v = objs_vector(obj_a, obj_b);

    FAIL_IF(!obj_a || !obj_b || !obj_a->physics || !obj_b->physics, 0);
    return (vector_magnitude(v));
}

float objs_angle(obj_t *obj_a, obj_t *obj_b)
{
    sfVector2f x_axis = {-1, 0};
    sfVector2f v_a = {0, 0};
    sfVector2f v_ab = {0, 0};
    float angle_ax = 0;
    float angle_abx = 0;

    FAIL_IF(!obj_a || !obj_b || !obj_a->physics || !obj_b->physics, 0);
    if (obj_a->physics->speed.x != 0 || obj_a->physics->speed.y != 0) {
        v_a = obj_a->physics->speed;
        angle_ax = angle_between_vectors(x_axis, v_a);
    }
    v_ab = objs_vector(obj_a, obj_b);
    angle_abx = angle_between_vectors(x_axis, v_ab);
    return (angle_abx - angle_ax);
}