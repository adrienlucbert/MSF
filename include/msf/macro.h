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
#define DEFAULT_GRAVITY     0.5
#define DEFAULT_RESTITUTION 0.5

#ifndef FAIL_IF
#define FAIL_IF(cond, exit_status)     if (cond) return (exit_status)
#define FAIL_IF_VOID(cond)  if (cond) return;
#endif /* !FAIL_IF */

#define VFUNC(THIS, FUNC, ...) if (((obj_t *)THIS)->vtable->FUNC) \
    ((obj_t *)THIS)->vtable->FUNC(THIS, __VA_ARGS__)
#define VGET(THIS, GETTER) ((obj_t *)THIS)->vtable->GETTER(THIS)

#endif /* !MSF_MACRO_H_ */