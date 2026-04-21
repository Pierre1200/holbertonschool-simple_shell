#include "shell.h"

/**
 * main - Entry point for the simple shell loop
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: The array of environment variables.
 * @line_count: count
 *
 * Return: Always 0
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
		/* Print the prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_line();
		/* Stop the loop when read_line reaches EOF */
		if (line == NULL)
			break;
		line_count++;
		/* Split the line into tokens */
		args = split_line(line);

		/* Handle built-in commands before trying to execute external ones */
		if (args != NULL && args[0] != NULL)
		{
			if (check_builtin(args, line, envp) == 0)
			{
				status = execute_cmd(args, argv[0], envp, line_count);
			}
			else
			{
				status = 0;
			}
		}
		free_array(args);
		free(line);
		args = NULL;
		line = NULL;
	}
	return (status);
}

