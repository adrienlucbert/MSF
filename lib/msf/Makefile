##
## EPITECH PROJECT, 2019
## modsf
## File description:
## Makefile
##

SRC			=	ll/list_met.c							\
				ll/node_tor.c							\
				ll/node_met.c							\
				hub/hub_tor.c							\
				hub/hub_met.c							\
				hub/hub_set.c							\
				hub/window_tor.c						\
				hub/window_met.c						\
				hub/global_evts.c						\
				evt/evt_tor.c							\
				evt/evt_met.c							\
				scene/scene_tor.c						\
				scene/scene_met.c						\
				scene/scene_set.c						\
				obj/obj_tor.c							\
				obj/obj_met.c							\
				obj/obj_set.c							\
				obj/mouse_evt.c							\
				obj/text/text_tor.c						\
				obj/text/text_met.c						\
				obj/text/text_set.c						\
				obj/text/text_get_s.c					\
				obj/text/text_get_t.c					\
				obj/text/text_set_s.c					\
				obj/text/text_set_t.c					\
				obj/text/text_vtable.c					\
				obj/input/input_tor.c					\
				obj/input/input_met.c					\
				obj/input/input_set.c					\
				obj/input/input_set_t.c					\
				obj/input/input_set_s.c					\
				obj/input/input_get_t.c					\
				obj/input/input_get_s.c					\
				obj/input/input_vtable.c				\
				obj/shape/circle/circle_tor.c			\
				obj/shape/circle/circle_set.c			\
				obj/shape/circle/circle_set_2.c			\
				obj/shape/circle/circle_met.c			\
				obj/shape/circle/circle_vtable.c		\
				obj/shape/rect/rect_tor.c				\
				obj/shape/rect/rect_set.c				\
				obj/shape/rect/rect_met.c				\
				obj/shape/rect/rect_vtable.c			\
				obj/anim/anim_tor.c						\
				obj/anim/anim_met.c						\
				obj/anim/anim_set_t.c					\
				obj/anim/anim_set_s.c					\
				obj/anim/anim_get_t.c					\
				obj/anim/anim_get_s.c					\
				obj/anim/anim_vtable.c					\
				obj/anim/animation/animation_tor.c		\
				obj/anim/animation/animation_met.c		\
				obj/anim/animation/animation_set.c		\
				obj/anim/animation/frame/frame_tor.c	\
				obj/anim/animation/frame/frame_met.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmsf.a

GRAPHICS	=	-l csfml-graphics
WINDOW		=	-l csfml-window
SYSTEM		=	-l csfml-system
AUDIO		=	-l csfml-audio
NETWORK		=	-l csfml-network

LDLIBS		=	-L../ -lmy $(GRAPHICS) $(SYSTEM) $(AUDIO) -lm
INCLUDE		=	-I../../include
CFLAGS		=	-Wextra -Wall -g $(INCLUDE) $(LDLIBS)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc ../$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re