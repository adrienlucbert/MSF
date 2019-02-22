/*
** EPITECH PROJECT, 2019
** modsf
** File description:
** macro
*/

#ifndef MSF_MACRO_H_
#define MSF_MACRO_H_

#define ABS(x)      (x < 0 ? -(x) : (x))
#define M_PI        acos(-1.0)
#define RAD(deg)    ((deg) * M_PI / 180)
#define DEG(rad)    ((rad) * 180 / M_PI)
#define G           9.81

#ifndef FAIL_IF
#define FAIL_IF(cond, exit_status)     if (cond) return (exit_status)
#define FAIL_IF_VOID(cond)  if (cond) return;
#endif /* !FAIL_IF */

#define VFUNC(THIS, FUNC, ...) if (THIS->vtable->FUNC) \
    THIS->vtable->FUNC(THIS, __VA_ARGS__)
#define VGET(THIS, GETTER) if (THIS->vtable->GETTER) \
    THIS->vtable->GETTER(THIS)

#endif /* !MSF_MACRO_H_ */