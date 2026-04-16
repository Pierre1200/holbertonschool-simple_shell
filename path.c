#include "shell.h"

/**
 * find_path - placeholder for PATH resolution
 * @command: command to resolve
 *
 * Return: NULL
 */
char *find_path(char *command)
{
	int i = 0;
	int result;
	char *path_copy = NULL, *token_path, *full_path;
	struct stat st;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			/*Copy whithout "PATH="*/
			path_copy = strdup(environ[i] + 5);
			break;
		}
		i++;
	}
	if (path_copy == NULL)
		return (NULL);
	token_path = strtok(path_copy, ":");
	while (token_path != NULL) /*loop for test each folders*/
	{
		full_path = malloc(strlen(token_path) + strlen(command) + 2); /*MemoryAlloc*/
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(full_path, token_path); /* Build path */
		strcat(full_path, "/");
		strcat(full_path, command);

		result = stat(full_path, &st); /*FILE EXISTS ?*/
		if (result == 0) /*SUCCESS*/
		{
			free(path_copy);
			return (full_path);
		}
		else /*FAILURE*/
		{
			free(full_path);
			token_path = strtok(NULL, ":");
		}
	}

	free(path_copy);
	return (NULL);
}
