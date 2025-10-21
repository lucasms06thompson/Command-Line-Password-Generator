# Makefile for passgen

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Target executable name
TARGET = passgen

# Source files
SRC = passgen.c

# Default rule: build the target
all: $(TARGET)

# Rule to link the object file into the final executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Rule to clean up build files
clean:
	rm -f $(TARGET)

# Phony targets are not actual files
.PHONY: all clean
