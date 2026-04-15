#include "shell.h"

/**
 * main - Entry point for the simple shell loop
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_line;

	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(0))
			printf("($) ");

		/*Simulation parser.c*/
		read_line = getline(&line, &len, stdin);

		if (read_line == -1)
		{
			free(line);
			exit(0);
		}

		if (read_line > 0 && line[read_line - 1] == '\n')
			line[read_line - 1] = '\0';

		check_builtin(line);
	}
	return (0);
}
