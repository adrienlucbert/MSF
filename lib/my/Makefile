##
## EPITECH PROJECT, 2018
## Libmy
## File description:
## Makefile
##

SRC	=	my_atoi.c													\
		my_putnbr.c													\
		my_itoa.c													\
		my_putchar.c												\
		my_putstr.c													\
		my_calloc.c													\
		my_memset.c													\
		my_realloc.c												\
		my_memcpy.c													\
		my_memcmp.c													\
		my_memlen.c													\
		my_memdup.c													\
		my_memcat.c													\
		my_memchr.c													\
		my_memmem.c													\
		my_strtok.c													\
		my_perror.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../../include -g

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc ../$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all
