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
LDFLAGS = -ld

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

# Default target
all: $(TARGET)

# Create directories if they don't exist
$(OBJ_DIR) $(OUTPUT_DIR) $(DATA_DIR):
	$(MKDIR) "$@"

# Main project build
$(TARGET): $(OBJS) $(MAIN_OBJ) | $(OUTPUT_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Build a specific test executable
$(OUTPUT_DIR)/test_%$(EXE): $(OBJ_DIR)/test_%.o $(OBJS) | $(OUTPUT_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(TESTFLAGS)

# Pattern rule for test targets
test_%: $(OUTPUT_DIR)/test_%$(EXE)
	@echo "Running $@..."
	@$<


$(DATA_DIR)/%: | $(DATA_DIR)
	$(MKDIR) "$(dir $@)"
	type nul > "$@"

generate_data: $(DATA_DIR)/input_arrays.txt
	$(PYTHON) $(SCRIPT_DIR)$(SEP)generate_arrays.py

evaluate: $(TARGET) generate_data
	.$(SEP)$(TARGET) $(DATA_DIR)$(SEP)input_arrays.txt $(DATA_DIR)$(SEP)result.csv

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
.PHONY: all clean generate_data evaluate visualize
