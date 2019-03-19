##
## EPITECH PROJECT, 2019
## MUL_my_defender_2018
## File description:
## Makefile
##

SRC			=	my_atoi.c													\
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
				my_perror.c													\
				my_format.c

OBJ			=	$(patsubst %.c,%.o,$(SRC))

NAME		=	libmy.a
PATHNAME	=	../$(NAME)

CSFML		=	-lcsfml-graphics -lcsfml-system -lcsfml-audio
LDLIBS		=	-L../ -lmy $(CSFML) -lm
INCLUDE		=	-I../../include
CFLAGS		=	-Wextra -Wall $(INCLUDE) $(LDLIBS)

all:
	uptodate=0;\
	if [ -f $(PATHNAME) ];then\
		uptodate=1;\
		for file in $(SRC);do\
			if [[ ! -f $${file//.c/.o} ]];then\
				uptodate=0;\
			fi;\
			if [[ -n "$$(find . -regex \.?\/?$$file -a -newer $(PATHNAME))" ]];then\
				uptodate=0;\
			fi;\
		done;\
	fi;\
	if [ $$uptodate == 1 ];then\
		echo "make: '$(NAME)' is up to date.";\
	else\
		rm -f $(PATHNAME);\
		make $(NAME);\
	fi;

$(NAME):
	status=1;\
	$(call TERMLOG,$(HEADER),BUILDING SOURCES : ,$(INFO),[$(CFLAGS)]);\
	for file in $(SRC);do\
		if [ ! -f $$file ];then\
			$(call TERMLOG,$(NORMAL),'$$file' is missing. ,$(ERROR),[NO FILE]);\
			status=0;\
			break;\
		else\
			cc -o $${file//.c/.o} -c $$file $(CFLAGS);\
			if [[ "$$?" == 0 ]];then\
				$(call TERMLOG,$(NORMAL),building '$$file' ,$(SUCCESS),[OK]);\
			else\
				status=0;\
				$(call TERMLOG,$(NORMAL),building '$$file' ,$(ERROR),[KO]);\
			fi;\
		fi;\
	done;\
	if [ "$$status" == 1 ];then\
		$(call TERMLOG,$(HEADER),\nARCHIVING OBJECTS : );\
		ar rc $(PATHNAME) $(OBJ);\
		if [[ "$$?" == 0 ]];then\
			$(call TERMLOG,$(NORMAL),creating '$(NAME)' ,$(SUCCESS),[OK]);\
		else\
			$(call TERMLOG,$(NORMAL),creating '$(NAME)' ,$(ERROR),[KO]);\
		fi;\
	fi;

clean:
	$(call TERMLOG,$(HEADER),DELETING OBJECTS : );\
	for obj in $(OBJ);do\
		rm -f $$obj;\
		if [ "$$?" == 0 ];then\
			$(call TERMLOG,$(NORMAL),removing '$$obj' ,$(SUCCESS),[OK]);\
		else\
			$(call TERMLOG,$(NORMAL),removing '$$obj' ,$(ERROR),[KO]);\
		fi;\
	done;

fclean:	clean
	$(call TERMLOG,$(HEADER),\nDELETING TARGET : );\
	rm -f $(PATHNAME);\
	if [ "$$?" == 0 ];then\
		$(call TERMLOG,$(NORMAL),removing '$(NAME)' ,$(SUCCESS),[OK]);\
	else\
		$(call TERMLOG,$(NORMAL),removing '$(NAME)' ,$(ERROR),[KO]);\
	fi;

re:	fclean all

.PHONY:	all clean fclean re

ifndef VERBOSE
.SILENT:
endif

define GET_PADDING
	$$(($$(tput cols) - $$(expr length "$1") + 1))
endef
define TERMLOG
	printf "$1%b$(NORMAL)$3%*b$(NORMAL)" "$2" $(call GET_PADDING,$2) "$4\n"
endef

NORMAL	=	\e[39m\e[0m
HEADER	=	\e[39m\e[1m
INFO	=	\e[93m
ERROR	=	\e[31m\e[1m
SUCCESS	=	\e[92m