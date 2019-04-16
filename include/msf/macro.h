/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** macro
*/

#ifndef MSF_MACRO_H_
#define MSF_MACRO_H_

#define ABS(x)              (x < 0 ? -(x) : (x))
#ifndef M_PI
#define M_PI            acos(-1.0)
#endif
#define RAD(deg)            ((deg) * M_PI / 180)
#define DEG(rad)            ((rad) * 180 / M_PI)

#ifndef FAIL_IF
#define FAIL_IF(cond, exit_status)     if (cond) return (exit_status)
#define FAIL_IF_VOID(cond)  if (cond) return;
#endif /* !FAIL_IF */

#define VECT2F(x, y) (sfVector2f){x, y}
#define VECT2U(x, y) (sfVector2u){x, y}
#define VECT2I(x, y) (sfVector2i){x, y}
#define RECT2I(left, top, width, height) (sfIntRect){left, top, width, height}
#define RECT2F(left, top, width, height) (sfFloatRect){left, top, width, height}
#define RGBA(R, G, B, A) (sfColor){R, G, B, A}

#define VFUNC(THIS, FUNC, ...) if (THIS && ((obj_t *)THIS)->vtable->FUNC) \
((obj_t *)THIS)->vtable->FUNC(THIS, __VA_ARGS__)
#define VGET(THIS, GETTER) ((obj_t *)THIS)->vtable->GETTER(THIS)

#define KRELEASED(evt, keycode)\
((evt.type == sfEvtKeyReleased && evt.key.code == keycode) ? 1 : 0)
#define KPRESSED(keycode) (sfKeyboard_isKeyPressed(keycode) ? 1 : 0)

#define CLICK(evt, keycode)\
((evt.mouseButton.type == sfEvtMouseButtonReleased && \
evt.mouseButton.button == keycode) ? 1 : 0)

#endif /* !MSF_MACRO_H_ */