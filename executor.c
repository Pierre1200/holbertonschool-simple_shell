#include "shell.h"

/**
 * execute_cmd - Exécute la commande passée en argument.
 * @args: Le tableau de mots renvoyé par split_line.
 * @argv0: Nom du programme shell.
 * Return: 1 pour continuer la boucle du shell, 0 pour arrêter.
 */
int execute_cmd(char **args, char *argv0)
{
	pid_t child;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	child = fork();

	if (child == 0)
	{
		execve(args[0], args, environ);
		print_error(argv0, args[0]);
		exit(EXIT_FAILURE);
	}

	else if (child == -1)
	{
		perror("Error");
	}

	else
	{
		wait(&status);
	}

	return (1);
}
