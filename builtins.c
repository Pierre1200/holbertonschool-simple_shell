#include "shell.h"

/**
 * check_builtin - checks and executes built-in commands
 * @command: user command line
 *
 * Return: 1 if builtin handled, 0 otherwise
 */
int check_builtin(char *command)
{
	int i = 0;

	if (command == NULL)
		return (0);

	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(0);
	}

	if (strcmp(command, "env") == 0)
	{
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (1);
	}

	printf("%s : command not found\n", command);
	return (0);
}
