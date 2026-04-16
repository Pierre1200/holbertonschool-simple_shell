#include "shell.h"

/**
 * main - Entry point for the simple shell loop
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **args = NULL;

	(void)argc;
	(void)argv;

	while (1)
	{
		/* Print the prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			printf("($) ");

		/* Read one full line from standard input */
		line = read_line();
		/* Stop the loop when read_line reaches EOF */
		if (line == NULL)
			break;

		/* Split the line into tokens */
		args = split_line(line);

		/* Handle built-in commands before trying to execute external ones */
		if (args[0] != NULL && check_builtin(args[0]) == 0)
			execute_cmd(args, argv[0]);

		/* Free the current command data before reading the next line */
		free_array(args);
		free(line);
		args = NULL;
		line = NULL;
	}
	return (0);
}

