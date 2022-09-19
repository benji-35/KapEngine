##
## ██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
## ██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
## █████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
## ██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
## ██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
## ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
##                                                                         
## by Benjamin DELVERT

#
# DO NOT TOUCH THIS FILE
# ANY CHANGES CAN DESTROY THE PROCESS TO COMPILE
#

COMPILER	=	g++

include Config/Makefile

SRC	=	$(ENGINE_PATH_COMPONENT)Component.cpp								\
		$(ENGINE_PATH_GAMEOBJECTS)GameObject.cpp							\
		$(ENGINE_PATH_SCENE)Scene.cpp										\
		$(ENGINE_PATH_SCENEMANAGER)SceneManager.cpp							\
		$(ENGINE_PATH_ENGINE)KapEngine.cpp									\
		$(ENGINE_PATH_INPUTS)Input.cpp										\
		$(ENGINE_PATH_COMPONENTS)Transform/Transform.cpp					\
		$(ENGINE_PATH_COMPONENTS)Camera/Camera.cpp							\
		$(ENGINE_PATH_GRAPHICAL)GraphicalLibManager.cpp						\
		$(ENGINE_PATH_GRAPHICAL)GraphicalLib.cpp							\
		$(ENGINE_PATH_LEGACY_GRAPHICAL)LegacyGraphicalLib.cpp				\
		$(ENGINE_PATH_DEBUG)Debug.cpp										\

LIB_NAME	=	libKapEngine.so

INCLUDES	+= 	$(ENGINE_INCLUDES) $(INCLUDE_UTILS)

PATH_CP_LIB	=	../

OBJ	=	$(SRC:.cpp=.o)

%.o: %.cpp
	@echo "$(LIB_NAME) < [CPP: $<]"
	@g++ -c $< $(INCLUDES) -o $@ -g -fPIC

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@g++ -shared -fPIC -o $(LIB_NAME) $(OBJ)
	@cp $(LIB_NAME) $(PATH_CP_LIB)$(LIB_NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(LIB_NAME)
	@rm -f $(PATH_CP_LIB)$(LIB_NAME)

re:	fclean all

.PHONY: all re fclean
