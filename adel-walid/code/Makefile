# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude
LIBS = -lm
LDFLAGS = -ld
TESTFLAGS = -lcunit

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
DATA_DIR = data
OUTPUT_DIR = bin
OBJ_DIR = obj
SCRIPT_DIR=scripts

# Source files (excluding main.c)
SRC = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
MAIN = $(SRC_DIR)/main.c
TESTS = $(wildcard $(TEST_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
MAIN_OBJ = $(OBJ_DIR)/main.o
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/test_%.o,$(TESTS))

# Target executable
TARGET = $(OUTPUT_DIR)/sorting_project

# Default target
all: $(TARGET)

# Create directories if they don't exist
$(OBJ_DIR) $(OUTPUT_DIR):
	mkdir -p $@

# Main project build
$(TARGET): $(OBJS) $(MAIN_OBJ) | $(OUTPUT_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Compile test files
$(OBJ_DIR)/test_%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Build a specific test executable
$(OUTPUT_DIR)/test_%: $(OBJ_DIR)/test_%.o $(OBJS) | $(OUTPUT_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(TESTFLAGS)

# Pattern rule for test targets
test_%: $(OUTPUT_DIR)/test_%
	@echo "Running $@..."
	@./$<

# Run all tests
TEST_TARGETS = $(patsubst $(TEST_DIR)/%.c,test_%,$(TESTS))
test: $(TEST_TARGETS)
	@echo "All tests completed." 

# Run a specific test
run_test: $(OUTPUT_DIR)/test_$(TEST_NAME)
	@echo "Running test $(TEST_NAME)..."
	./$(OUTPUT_DIR)/test_$(TEST_NAME)


$(DATA_DIR)/% :
	mkdir -p $(dir $@)
	touch $@

generate_data: $(DATA_DIR)/input_arrays.txt
	python3 $(SCRIPT_DIR)/generate_arrays.py

evaluate: $(TARGET) generate_data
	./$(TARGET) $(DATA_DIR)/input_arrays.txt $(DATA_DIR)/result.csv

visualize: evaluate
	python3 $(SCRIPT_DIR)/visualize_result.py

# Clean target
clean:
	rm -rf $(OUTPUT_DIR) $(OBJECT_DIR)

# Phony targets
.PHONY: all clean test run_test
