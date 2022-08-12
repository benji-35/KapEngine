##
## ██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
## ██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
## █████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
## ██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
## ██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
## ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
##                                                                         
## by Benjamin DELVERT

# game name binary
GAME_NAME	=	TestGame

# relative path of directory that contain your .hpp component. You have to insert at front "-I"
# ex: (hpp: ) -I Assets/Components/ (cpp: ) Assets/Components/MyComponent.cpp
COMPONENTS_HPP	=	-I Assets/Components

# relative path of cpp component file
COMPONENTS_CPP	=

# same as component hpp
#
GRAPHICAL_LIB_HPP	=

# same as component cpp
GRAPHICAL_LIB_CPP	=


#
#	DO NOT TOUCH AFTER THIS LINE
#

MAIN	=	Main.cpp

SRC	+=	$(MAIN)
SRC	+=	$(COMPONENTS_CPP)
SRC	+=	$(GRAPHICAL_LIB_CPP)

include ../KapEngine/Config/Makefile

INCLUDES	+=	$(COMPONENTS_HPP)
INCLUDES	+=	$(GRAPHICAL_LIB_HPP)
INCLUDES	+=	$(ENGINE_INCLUDES_EG)

OBJ	=	$(SRC:.cpp=.o)

LIB	=	-L. -lKapEngine

%.o: %.cpp
	@echo "$(GAME_NAME) < [CPP: $<]"
	@g++ -c $< $(INCLUDES) -o $@ -g $(LIB)

all:	$(GAME_NAME)

$(GAME_NAME): $(OBJ)
	@g++ $(OBJ) $(INCLUDES) -o $(GAME_NAME) $(LIB)
	@cp $(GAME_NAME) ../$(GAME_NAME)

fclean: clean
	@rm -f $(GAME_NAME)
	@rm -f ../$(GAME_NAME)

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all re fclean
