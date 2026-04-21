#include "shell.h"

/**
 * main - Entry point for the simple shell loop.
 * @argc: Argument count (unused).
 * @argv: Argument vector (contains the name of the program).
 * @envp: The array of environment variables.
 *
 * Return: The exit status of the last executed command.
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	char **args = NULL;
	int status = 0;
	int line_count = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_line();
		if (line == NULL)
			break;

		line_count++;
		args = split_line(line);

		if (args == NULL || args[0] == NULL)
		{
			free_array(args);
			free(line);
			continue;
		}

		if (check_builtin(args, line, envp, status) == 0)
		{
			status = execute_cmd(args, argv[0], envp, line_count);
		}
		else
		{
			status = 0;
		}
		free_array(args);
		free(line);
		args = NULL;
		line = NULL;
	}
	return (status);
}
