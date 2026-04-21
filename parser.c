#include "shell.h"

/**
 * read_line - Reads a line of input from standard input.
 *
 * Return: A pointer to the read string, or NULL on EOF/failure.
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
		return (NULL);
	}

	return (line);
}

/**
 * split_line - Splits a string into an array of words (tokens).
 * @line: The raw string returned by read_line.
 *
 * Return: A NULL-terminated array of pointers to each word.
 */
char **split_line(char *line)
{
	int buff_tab = 64;
	int i = 0;
	char **tokens;
	char *token;

	tokens = malloc(buff_tab * sizeof(char *));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, "Allocation error\n", 17);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}

	tokens[i] = NULL;

	return (tokens);
}
