CC = gcc

RAYLIB_PATH = /opt/homebrew/opt/raylib

CFLAGS = -Wall -Wextra -std=c11 -g -IInc -I$(RAYLIB_PATH)/include

LDFLAGS = -L$(RAYLIB_PATH)/lib -lraylib \
          -framework OpenGL \
          -framework Cocoa \
          -framework IOKit \
          -framework CoreVideo

BUILD = build

SRC = Src/main.c Src/game.c Src/physics.c Src/render_raylib.c \
      Src/vector2.c Src/input.c Src/object_list.c

OBJ = $(patsubst Src/%.c,$(BUILD)/%.o,$(SRC))

TARGET = $(BUILD)/main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(BUILD)/%.o: Src/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

.PHONY: all clean