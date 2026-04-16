#include "shell.h"

/**
* free_array - Libère le tableau de pointeurs généré par split_line.
* @args: Le tableau à libérer.
*/
void free_array(char **args)
{
	if (args != NULL)
	{
		free(args);
	}
}

/**
* print_error - Affiche un message d'erreur si la commande est introuvable.
* @argv0: Le nom du programme (généralement argv[0], ex: ./hsh).
* @cmd: La commande qui a posé problème (ex: qwerty).
*/
void print_error(char *argv0, char *cmd)
{
	fprintf(stderr, "%s: 1: %s: not found\n", argv0, cmd);
}
