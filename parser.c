#include "shell.h"

/**
 * read_line - Lit la ligne tapée par l'utilisateur (le client).
 *
 * Return: Un pointeur vers la chaîne de caractères lue.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t retgetl;

	retgetl = getline(&line, &len, stdin);

	if (retgetl == -1)
	{
		free(line);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		return (NULL);
	}

	return (line);
}

/**
 * split_line - Découpe la chaîne de caractères en tableau de mots (tokens).
 * @line: La chaîne de caractères brute renvoyée par read_line.
 *
 * Return: Un tableau de pointeurs vers chaque mot (NULL terminated).
 */
char **split_line(char *line)
{
	int buff_tab = 64;
	int i = 0;
	char **tokens; /* tableau */
	char *token;

	tokens = malloc(buff_tab * sizeof(char *));
		if (tokens == NULL)
		{
			write(STDERR_FILENO, "Allocation error\n", 17);
			exit(EXIT_FAILURE);
		}

	token = strtok(line, " \n");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}

	tokens[i] = NULL;

	return (tokens);
}
