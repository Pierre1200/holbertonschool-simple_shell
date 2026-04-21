# Executable name
NAME = hsh

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# List of source files
SRC = main.c \
      parser.c \
      executor.c \
      path.c \
      builtins.c \
      utils.c

# Conversion of .c files to .o (object files)
OBJ = $(SRC:.c=.o)

# Main rule (default)
all: $(NAME)

# Link object files to create the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to remove object files
clean:
	rm -f $(OBJ)

# Rule to remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to re-compile from scratch
re: fclean all

# Specify that these rules are not files
.PHONY: all clean fclean re