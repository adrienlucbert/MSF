/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** ll
*/

#ifndef MSF_LL_H_
#define MSF_LL_H_

#include "my.h"

/*
**  STRUCTS
*/

/*
**  Node
**      label       node identifier
**      data        node data
**      next        following node in the list
**      dtor        destructor function (used to free data)
*/
struct msf_node_s {
    char *label;
    void *next;
    void (*dtor)(void *);
};

/*
**  PROTOTYPES
*/
// NODE TOR
void *node_new(char *label, void *next);
void *node_ctor(void *node, char *label, void *next);
void node_dtor(void *node);
void node_destroy(void *node);

// NODE MET
void node_pop(void *node);

// LIST MET
void *list_append(void *begin, void *node);
void list_destroy(void *begin);
void list_apply(void *begin, void (*func)(void *));
void *list_fetch(void *begin, char *label);

#endif /* !MSF_LL_H_ */