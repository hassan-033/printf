#OBJS specifies which files to compile as part of the project
OBJS = *.c


#CC specifes which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#  -I where to find include files e.g -Iinc
COMPILER_FLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format

#LINKER_FLAGS specifies the libraries we're linking against e.g -lSDL2 -lm

#OBJ_NAME specifies the name of our executable
OBJ_NAME = printf


#This is the target that compiles our executable
all:	$(OBJS)
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(OBJS) -o $(OBJ_NAME)
