CC := gcc
CFLAGS := -Wall -Wextra -Iinclude -MMD -MP
LDFLAGS :=

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj

# Find all source files in the src directory
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Generate the corresponding object file names
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Generate the corresponding dependency file names
DEPS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.d,$(SRCS))

# Main target
TARGET := $(BIN_DIR)/main

all: $(TARGET)

$(TARGET): $(OBJS)
    @mkdir -p $(BIN_DIR)
    @$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    @$(CC) $(CFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
    @rm -rf $(BUILD_DIR)

.PHONY: all clean