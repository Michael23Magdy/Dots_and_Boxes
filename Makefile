all: compile link run


# source file list
f = main
CPP_FILES := $(f).cpp
#CPP_FILES += imp.cpp

# obj files list
OBJ_FILES := $(f).o
#OBJ_FILES += imp.o

# lib list
LIB_LIST := -lsfml-graphics
LIB_LIST += -lsfml-window
LIB_LIST += -lsfml-system

INCLUDED_FILES = colors.cpp
INCLUDED_FILES += board.cpp
INCLUDED_FILES += shapes.cpp
#CXX flags
CXX_FLAGS := -c
CXX_FLAGS += -w

compile:
	@g++ $(CXX_FLAGS) $(CPP_FILES) 
link:compile
	@g++ $(OBJ_FILES) -o $(f) $(LIB_LIST) $(INCLUDED_FILES)
run:link
	./$(f)
