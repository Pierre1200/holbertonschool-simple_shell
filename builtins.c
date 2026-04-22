#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the variable to find (e.g., "HOME").
 * @envp: The array of environment variables.
 *
 * Return: A pointer to the value string, or NULL if not found.
 */
char *_getenv(const char *name, char **envp)
{
	int i = 0;
	size_t len;

	if (name == NULL || envp == NULL)
		return (NULL);

	len = strlen(name);
	while (envp[i])
	{
		/* Checks if the line starts with "name" and is followed by a "=" */
		if (strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
		{
		/* Returns a pointer just after the '=' sign */
			return (envp[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

/**
 * check_builtin - Checks and executes built-in commands.
 * @args: Array of strings containing the command and its arguments.
 * @line: The full string read by getline (needed for cleanup before exit).
 * @envp: The array of environment variables.
 * @status: The exit status of the last executed command.
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int check_builtin(char **args, char *line, char **envp, int status)
{
	int i = 0;

	if (args == NULL || args[0] == NULL)
	return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		free_array(args);
		exit(status);
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

	if (strcmp(args[0], "cd") == 0)
	{
		char *home;

		if (args[1] == NULL)
		{
			home = _getenv("HOME", envp);
			if (home != NULL)
				chdir(home);
		}
		else if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
		return (1);
	}
return (0);
}
