CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O3
SRC_DIR = src/linalg/matrix
BUILD_DIR = build
TARGET = $(BUILD_DIR)/main

SRC = $(SRC_DIR)/matrix.c main.c
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC)))

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c into .o inside build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean run
