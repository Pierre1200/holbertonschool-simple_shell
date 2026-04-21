#include "shell.h"

/**
* execute_cmd - Executes the command passed as an argument.
* @args: The array of words returned by split_line.
* @argv0: The name of the shell program.
* @envp: The array of environment variables.
*
* Return: 1 to continue the shell loop, 0 to stop.
*/
int execute_cmd(char **args, char *argv0, char **envp)
{
	pid_t child;
	int status;

	char *command_path = NULL;

	if (args[0] == NULL)
		return (1);

	if (strchr(args[0], '/') != NULL)
	{
		if (access(args[0], X_OK) == 0)
			command_path = strdup(args[0]);
	}
	else
	{
		command_path = find_path(args[0], envp);
	}
	if (command_path == NULL)
	{
		print_error(argv0, args[0]);
		return (1);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(command_path, args, envp) == -1)
		{
			perror(argv0);
			free(command_path);
			_exit(127);
		}
	}
	else if (child == -1)
		perror("fork");
	else
		wait(&status);

	free(command_path);
	return (1);
}
