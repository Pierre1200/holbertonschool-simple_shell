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
		/*Verif du mode interactif*/
		if (isatty(0))
			printf("($) ");

		/*Simulation parser.c*/
		read_line = getline(&line, &len, stdin);

		/*Gestion des EOF*/
		if (read_line == -1)
		{
			free(line);
			exit(0);
		}

		/*Simulation début de parsing (découpe)*/
		if (read_line > 0 && line[read_line - 1] == '\n')
			line[read_line - 1] = '\0';

		/*Simulation si ce n'est pas un builtin*/
		if (check_builtin(line) == 0)
		{
		printf("%s : Command not found\n", line);
		}

		check_builtin(line);
	}
	return (0);
}
