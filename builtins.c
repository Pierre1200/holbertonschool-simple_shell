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
	/* EXIT: Free memory and terminate the shell */
	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		free_array(args);
		exit(0);
	}
	/* ENV: Print all environment variables */
	if (strcmp(args[0], "env") == 0)
	{
		while (envp[i] != NULL)
		{
			printf("%s\n", envp[i]);
			i++;
		}
		return (1);
	}
	/* CD: Change the current working directory */
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			/* No argument: go to HOME directory */
			chdir(getenv("HOME"));
		}
		else
		{
			/* Try to go to specified directory and handle errors */
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
	return (1);
	}
	return (0); /* No built-in found, continue to external commands */
}
