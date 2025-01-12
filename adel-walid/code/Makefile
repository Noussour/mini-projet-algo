# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude -lm
LDFLAGS = -ld
TESTFLAGS = -lcunit

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
DATA_DIR = data
OUTPUT_DIR = bin
OBJECT_DIR = obj
SCRIPT_DIR = scripts

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)
TESTS = $(wildcard $(TEST_DIR)/*.c)

# Object files with new directory
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SRC))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(OBJECT_DIR)/test_%.o, $(TESTS))
TEST_TARGETS = $(patsubst $(TEST_DIR)/%.c, $(OUTPUT_DIR)/test_%, $(TESTS))

# Target executable
TARGET = $(OUTPUT_DIR)/sorting_project

# Default target
all: $(TARGET)

# Main project build
$(TARGET): $(OBJS) | $(OUTPUT_DIR)
	$(CC) -o $@ $^ $(CFLAGS)

# Pattern rule for object files
$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJECT_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Pattern rule for test object files
$(OBJECT_DIR)/test_%.o: $(TEST_DIR)/%.c | $(OBJECT_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(TESTFLAGS)

# Create directories if not exists
$(OUTPUT_DIR) $(OBJECT_DIR):
	mkdir -p $@

# Build a specific test executable
$(OUTPUT_DIR)/test_%: $(OBJECT_DIR)/test_%.o $(OBJS) | $(OUTPUT_DIR)
	$(CC) -o $@ $^ $(CFLAGS) $(TESTFLAGS)

# Run all tests
test: $(TEST_TARGETS)
	@echo "Running all tests..."
	@for test in $(TEST_TARGETS); do \
		echo "Running $$test..."; \
		./$$test; \
	done

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
