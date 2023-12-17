
# source file list
CPP_EXCUTABLE_NAME = Game
CPP_FILES := main.cpp

# obj files list
OBJ_FILES := main.o

# lib list
LIB_LIST := -lsfml-graphics
LIB_LIST += -lsfml-window
LIB_LIST += -lsfml-system

INCLUDED_FILES = colors.cpp
INCLUDED_FILES += board.cpp
INCLUDED_FILES += shapes.cpp
INCLUDED_FILES += board_text.cpp
INCLUDED_FILES += game_logic.cpp
#CXX flags
CXX_FLAGS := -c
CXX_FLAGS += -w

compile:
	@g++ $(CXX_FLAGS) $(CPP_FILES) 
link:compile
	@g++ $(OBJ_FILES) -o $(CPP_EXCUTABLE_NAME).exe $(LIB_LIST) $(INCLUDED_FILES)
run:link
	./$(CPP_EXCUTABLE_NAME).exe
