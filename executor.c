#include "shell.h"

/**
 * execute_cmd - Executes the command passed as an argument.
 * @args: The array of words returned by split_line.
 * @argv0: The name of the shell program.
 * @envp: The array of environment variables.
 * @line_count: The number of lines read so far.
 *
 * Return: The exit status of the executed command.
 */
int execute_cmd(char **args, char *argv0, char **envp, int line_count)
{
	pid_t child;
	int status;
	char *path = NULL;

	if (args[0] == NULL)
		return (1);

	if (strchr(args[0], '/') && access(args[0], X_OK) == 0)
		path = strdup(args[0]);
	else if (!strchr(args[0], '/'))
		path = find_path(args[0], envp);

	if (path == NULL)
	{
		print_error(argv0, args[0], line_count);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		execve(path, args, envp);
		free(path);
		_exit(127);
	}
	else if (child == -1)
	{
		free(path);
		return (1);
	}

	wait(&status);
	free(path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
