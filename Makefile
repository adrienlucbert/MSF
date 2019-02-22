##
## EPITECH PROJECT, 2019
## modsf
## File description:
## Makefile
##

SRC			=	src/main.c		\
				src/menu.c

OBJ			=	$(SRC:.c=.o)

NAME		=	msf

GRAPHICS	=	-l csfml-graphics
WINDOW		=	-l csfml-window
SYSTEM		=	-l csfml-system
AUDIO		=	-l csfml-audio
NETWORK		=	-l csfml-network

LDLIBS		=	-Llib -lmsf -lmy $(GRAPHICS) $(SYSTEM) $(AUDIO)
INCLUDE		=	-Iinclude
CFLAGS		=	-Werror -Wextra -Wall -g $(INCLUDE) $(LDLIBS)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(MAKE) -C lib/msf
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(MAKE) clean -C lib/my
	$(MAKE) clean -C lib/msf
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C lib/my
	$(MAKE) fclean -C lib/msf
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re