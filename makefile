# Compiler and flags
CC = gcc
CFLAGS = -fPIC
LDFLAGS = -shared

# Source files and object files
SRC = $(wildcard ./src/sdk/*.c) 
OBJ = $(SRC:.c=.o)

# Output shared object file
LIB = bcpsdk.so

# Default target: compile and link the shared object
all: $(LIB)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the .so file
$(LIB): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

# Clean rule to remove object files and the shared library
clean:
	rm -f $(OBJ) $(LIB)

.PHONY: all clean
