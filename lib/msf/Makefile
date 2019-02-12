##
## EPITECH PROJECT, 2019
## modsf
## File description:
## Makefile
##

SRC			=	ll/list_met.c				\
				ll/node_tor.c				\
				ll/node_met.c				\
				vector.c					\
				hub/hub_tor.c				\
				hub/hub_met.c				\
				hub/window_tor.c			\
				hub/window_met.c			\
				hub/global_evts.c			\
				evt/evt_tor.c				\
				scene/scene_tor.c			\
				scene/scene_met.c			\
				obj/obj_tor.c				\
				obj/mouse_evt.c				\
				obj/text/text_tor.c			\
				obj/text/text_met.c			\
				obj/input/input_tor.c		\
				obj/input/input_met.c		\
				obj/animated/animated_tor.c	\
				obj/animated/animated_met.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmsf.a

GRAPHICS	=	-l csfml-graphics
WINDOW		=	-l csfml-window
SYSTEM		=	-l csfml-system
AUDIO		=	-l csfml-audio
NETWORK		=	-l csfml-network

LDLIBS		=	-L../ -lmy $(GRAPHICS) $(SYSTEM) $(AUDIO) -lm
INCLUDE		=	-I../../include
CFLAGS		=	-Werror -Wextra -Wall -g $(INCLUDE) $(LDLIBS)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc ../$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re