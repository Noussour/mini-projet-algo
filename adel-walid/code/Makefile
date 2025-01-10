# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -ld
TESTFLAGS = -lcunit

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
DATA_DIR = data
OUTPUT_DIR = bin
SCRIPT_DIR = scripts

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)
TESTS = $(wildcard $(TEST_DIR)/*.c)

# Object files
OBJS = $(patsubst %.c, %.o, $(SRC))

# Target executable
TARGET = $(OUTPUT_DIR)/sorting_project

# Default target
all: $(TARGET)

# Main project build
$(TARGET): $(OBJS) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Create output directory if not exists
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Build a specific test executable
$(OUTPUT_DIR)/%: $(TEST_DIR)/%.c $(SRC) | $(OUTPUT_DIR)
	$(CC) -o $@ $< $(SRC) $(CFLAGS) $(TESTFLAGS)

# Run all tests
test: $(TEST_TARGETS)
	@echo "Running all tests..."
	@for test in $(TEST_TARGETS); do \
		echo "Running $$test..."; \
		$$test; \
	done

# Run a specific test
run_test: $(OUTPUT_DIR)/$(TEST_NAME)
	@echo "Running test $(TEST_NAME)..."
	@$(OUTPUT_DIR)/$(TEST_NAME)

# Clean target
clean:
	rm -rf $(OUTPUT_DIR)

# Parameterized test target
.PHONY: all clean test run_test

