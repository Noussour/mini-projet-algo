# Detect OS
ifeq ($(OS),Windows_NT)
	PYTHON = python
	RM = del /Q /F
	RMDIR = rmdir /Q /S
	MKDIR = if not exist "$@" mkdir
	SEP = \\
	EXE = .exe
else
	PYTHON = python3
	RM = rm -f
	RMDIR = rm -rf
	MKDIR = mkdir -p
	SEP = /
	EXE =
endif

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude
LIBS = -lm

# Directories
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data
OUTPUT_DIR = bin
OBJ_DIR = obj
SCRIPT_DIR = scripts

# Source files (excluding main.c)
SRC = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
MAIN = $(SRC_DIR)/main.c

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
MAIN_OBJ = $(OBJ_DIR)/main.o

# Target executable
TARGET = $(OUTPUT_DIR)$(SEP)sorting_project$(EXE)

# Array sizes to test (customizable via command line)
SIZES ?= 1000 5000 10000  # Default sizes if none are provided

# Default target
all: visualize

# Create directories if they don't exist
$(OBJ_DIR) $(OUTPUT_DIR) $(DATA_DIR):
	$(MKDIR) "$@"

# Main project build
$(TARGET): $(OBJS) $(MAIN_OBJ) | $(OUTPUT_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Evaluate sorting algorithms with generated arrays
evaluate: $(TARGET) | $(DATA_DIR)
	$(TARGET) $(DATA_DIR)$(SEP)result.csv $(SIZES)

# Visualize results (depends on evaluate)
visualize: evaluate
	$(PYTHON) $(SCRIPT_DIR)$(SEP)visualize_result.py


# Clean target
clean:
	$(RMDIR) $(OUTPUT_DIR)
	$(RMDIR) $(OBJ_DIR)
ifeq ($(OS),Windows_NT)
	if exist "$(DATA_DIR)" $(RMDIR) $(DATA_DIR)
else
	$(RMDIR) $(DATA_DIR)
endif

# Phony targets
.PHONY: all clean evaluate visualize