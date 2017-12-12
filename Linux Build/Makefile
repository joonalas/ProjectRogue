#OBJS specifies which files to compile
OBJS = ../source/* ../SDL/*

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#SEARCH_FLAGS tell preprocessor where to find header files
SEARCH_FLAGS = -I/usr/include/SDL2/ -I../headers/

#OBJ_NAME specifies the name of our executable
OBJ_NAME = ../application/rogue

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(SEARCH_FLAGS) -o $(OBJ_NAME)

#This is the target for running the compiled project
run : $(OBJ_NAME)
	$(OBJ_NAME)