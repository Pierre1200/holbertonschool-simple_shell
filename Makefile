# Nom de l'exécutable
NAME = hsh

# Compilateur et Flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Liste des fichiers source (tous tes .c)
SRC = main.c \
      parser.c \
      executor.c \
      path.c \
      builtins.c \
      utils.c

# Transformation des .c en .o (fichiers objets)
OBJ = $(SRC:.c=.o)

# Règle principale (par défaut)
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Règle pour nettoyer les fichiers objets
clean:
	rm -f $(OBJ)

# Règle pour nettoyer tout (objets + exécutable)
fclean: clean
	rm -f $(NAME)

# Règle pour re-compiler de zéro
re: fclean all

.PHONY: all clean fclean re