## 
## ██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗    ███████╗██████╗ ██╗████████╗ ██████╗ ██████╗ 
## ██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝    ██╔════╝██╔══██╗██║╚══██╔══╝██╔═══██╗██╔══██╗
## █████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗      █████╗  ██║  ██║██║   ██║   ██║   ██║██████╔╝
## ██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝      ██╔══╝  ██║  ██║██║   ██║   ██║   ██║██╔══██╗
## ██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗    ███████╗██████╔╝██║   ██║   ╚██████╔╝██║  ██║
## ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝    ╚══════╝╚═════╝ ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝
##                                                                                                                          
## By Benjamin DELVERT

#
# KapEngine Edior is made to create your game with a UI editor
# Everything write here must not be edited
#


BIN = KapEngineUI

include ../KapEngine/Config/Makefile

COMPILER	=	g++ $(CPP_VERSION)

INCLUDES	+=	$(ENGINE_INCLUDES_EG)  $(INCLUDE_UTILS)

MAIN	=	Main.cpp

SRC +=	$(MAIN)

OBJ = $(SRC:.cpp=.o)

LIB	=	-L. -lKapEngine

%.o: %.cpp
	@echo "$(GAME_NAME) < [CPP: $<]"
	@$(COMPILER) -c $< $(INCLUDES) -o $@ -g $(LIB)

all:	$(BIN)

$(BIN):	$(OBJ)
	@$(COMPILER) $(OBJ) $(INCLUDES) -o $(BIN) $(LIB)
	@cp $(BIN) ../$(BIN)

re: fclean all

fclean: clean
	rm -f $(BIN)
	rm -f ../$(BIN)

clean:
	rm -f $(OBJ)

.PHONY: all re fclean
