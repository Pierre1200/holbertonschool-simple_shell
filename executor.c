#include "shell.h"

/**
 * execute_cmd - Exécute la commande passée en argument.
 * @args: Le tableau de mots renvoyé par split_line.
 * @argv0: Nom du programme shell.
 * @envp: Environ
 * Return: 1 pour continuer la boucle du shell, 0 pour arrêter.
 */
int execute_cmd(char **args, char *argv0, char **envp)
{
	pid_t child;
	int status;
	char *command_path;

	if (args[0] == NULL)
	{
		return (1);
	}

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
