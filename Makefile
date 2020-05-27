CC=g++
CFLAGS=-Wall -g
LIBS=-lglut -lGL -lGLU -lSOIL

APPNAME := 3d_scene.out
SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(APPNAME)

$(APPNAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(APPNAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $@

clean:
	$(RM) -r $(OBJ_DIR) $(APPNAME)

.PHONY: all clean