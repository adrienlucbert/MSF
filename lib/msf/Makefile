##
## EPITECH PROJECT, 2019
## MUL_my_defender_2018
## File description:
## Makefile
##

SRC			=	utils/vector.c							\
				utils/objs.c							\
				ll/list_met.c							\
				ll/node_tor.c							\
				ll/node_met.c							\
				hub/hub_tor.c							\
				hub/hub_met.c							\
				hub/hub_set.c							\
				hub/window_tor.c						\
				hub/window_set.c						\
				hub/window_met.c						\
				hub/global_evts.c						\
				evt/evt_tor.c							\
				evt/evt_met.c							\
				scene/scene_tor.c						\
				scene/scene_met.c						\
				scene/scene_set.c						\
				scene/scene_clear_objs.c				\
				sound/sound_buffer_tor.c				\
				sound/sound_hub_set.c					\
				sound/sound_scene_set.c					\
				sound/sound_scene_set_global.c			\
				sound/sound_obj_set.c					\
				obj/obj_tor.c							\
				obj/obj_met.c							\
				obj/obj_set.c							\
				obj/mouse_evt.c							\
				obj/physics/physics_tor.c				\
				obj/physics/physics_met.c				\
				obj/physics/physics_set.c				\
				obj/physics/manifold_tor.c				\
				obj/physics/manifold_met.c				\
				obj/physics/check_collisions.c			\
				obj/physics/apply_collisions.c			\
				obj/text/text_tor.c						\
				obj/text/text_met.c						\
				obj/text/text_set.c						\
				obj/text/text_get.c						\
				obj/text/text_get_s.c					\
				obj/text/text_get_t.c					\
				obj/text/text_set_s.c					\
				obj/text/text_set_t.c					\
				obj/text/text_vtable.c					\
				obj/input/input_tor.c					\
				obj/input/input_met.c					\
				obj/input/input_set.c					\
				obj/input/input_set_t.c					\
				obj/input/input_get_t.c					\
				obj/input/input_get_s.c					\
				obj/input/input_vtable.c				\
				obj/shape/circle/circle_tor.c			\
				obj/shape/circle/circle_set.c			\
				obj/shape/circle/circle_set_t.c			\
				obj/shape/circle/circle_set_s.c			\
				obj/shape/circle/circle_get.c			\
				obj/shape/circle/circle_get_t.c			\
				obj/shape/circle/circle_get_s.c			\
				obj/shape/circle/circle_met.c			\
				obj/shape/circle/circle_vtable.c		\
				obj/shape/rect/rect_tor.c				\
				obj/shape/rect/rect_set_t.c				\
				obj/shape/rect/rect_set_s.c				\
				obj/shape/rect/rect_get.c				\
				obj/shape/rect/rect_get_t.c				\
				obj/shape/rect/rect_get_s.c				\
				obj/shape/rect/rect_met.c				\
				obj/shape/rect/rect_vtable.c			\
				obj/anim/anim_tor.c						\
				obj/anim/anim_met.c						\
				obj/anim/anim_set_t.c					\
				obj/anim/anim_set_s.c					\
				obj/anim/anim_get.c						\
				obj/anim/anim_get_t.c					\
				obj/anim/anim_get_s.c					\
				obj/anim/anim_vtable.c					\
				obj/anim/animation/animation_tor.c		\
				obj/anim/animation/animation_met.c		\
				obj/anim/animation/animation_set.c		\
				obj/anim/animation/frame/frame_tor.c	\
				obj/anim/animation/frame/frame_met.c	\
				obj/sound/sound_tor.c					\
				obj/sound/sound_set.c					\
				obj/sound/sound_get.c					\
				obj/sound/sound_vtable.c				\
				obj/sound/sound_met.c					\

OBJ			=	$(patsubst %.c,%.o,$(SRC))

DEPS		=	../my

NAME		=	libmsf.a
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