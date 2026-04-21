#include "shell.h"



/**
 * check_builtin - Vérifie et exécute les commandes intégrées (built-ins).
 * @args: Le tableau de mots (pour vérifier la commande et ses arguments).
 * @line: La ligne complète lue par getline (pour le nettoyage en cas d'exit).
 * @envp: Environement system
 *
 * Return: 1 si un built-in a été exécuté, 0 sinon.
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
		while (envp[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (1);
	}

	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
	return (1);
	}

	return (0);
}
