#include "shell.h"

/**
 * check_builtin - Checks and executes built-in commands.
 * @args: Array of strings containing the command and its arguments.
 * @line: The full string read by getline (needed for cleanup before exit).
 * @envp: The array of environment variables.
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int check_builtin(char **args, char *line, char **envp)
{
	int i = 0;

	if (args == NULL || args[0] == NULL)
	return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		free_array(args);
		exit(0);
	}
	if (strcmp(args[0], "env") == 0)
	{
		while (envp[i])
		{
			write(STDOUT_FILENO, envp[i], strlen(envp[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	return (1);
	}
return (0);
}