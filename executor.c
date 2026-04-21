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
	char *command_path;

	if (args[0] == NULL)
		return (1);

	command_path = find_path(args[0], envp);
	if (command_path == NULL)
		command_path = args[0];

	child = fork();

	if (child == 0)
	{
		execve(command_path, args, envp);
		print_error(argv0, args[0]);
		if (command_path != args[0])
			free(command_path);
		exit(EXIT_FAILURE);
	}
	else if (child == -1)
	{
		perror("Error");
	}
	else
	{
		wait(&status);
		if (command_path != args[0])
			free(command_path);
	}

	return (1);
}
