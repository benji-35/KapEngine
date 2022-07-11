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

PATH_COMPONENTS		=	Components/
PATH_COMPONENT		= 	Component/
PATH_ENGINE			=	Engine/
PATH_ERRORS			=	Errors/
PATH_GAMEOBJECTS	=	GameObject/
PATH_SCENE			=	SceneManagement/Scene/
PATH_SCENEMANAGER	=	SceneManagement/SceneManager/
PATH_TOOLS			=	Tools/
PATH_GRAPHICAL		=	GraphicalLib/

INCLUDES	=	-I $(PATH_COMPONENT)										\
				-I $(PATH_COMPONENTS)										\
				-I $(PATH_ENGINE)											\
				-I $(PATH_ERRORS)											\
				-I $(PATH_GAMEOBJECTS)										\
				-I $(PATH_SCENE)											\
				-I $(PATH_SCENEMANAGER)										\
				-I $(PATH_TOOLS)											\
				-I $(PATH_GRAPHICAL)										\

SRC	=	$(PATH_COMPONENT)Component.cpp										\
		$(PATH_GAMEOBJECTS)GameObject.cpp									\
		$(PATH_SCENE)Scene.cpp												\
		$(PATH_SCENEMANAGER)SceneManager.cpp								\
		$(PATH_ENGINE)Engine.cpp											\
		$(PATH_COMPONENTS)Transform/Transform.cpp							\

LIB_NAME	=	KapEngine.so

PATH_CP_LIB	=	../

OBJ	=	$(SRC:.cpp=.o)

%.o: %.cpp
	@echo "$(LIB_NAME) < [CPP: $<]"
	@g++ -c $< $(INCLUDES) -o $@ -g -fPIC

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@gcc -shared -fPIC -o $(LIB_NAME) $(OBJ)
	@cp $(LIB_NAME) $(PATH_CP_LIB)$(LIB_NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(LIB_NAME)
	@rm -f $(PATH_CP_LIB)$(LIB_NAME)

re:	fclean all
