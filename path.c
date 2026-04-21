#include "shell.h"

/**
 * get_path_env - Finds and copies the PATH variable from environment.
 * @envp: The array of environment variables.
 *
 * Return: A copy of the PATH string, or NULL if not found.
 */

char *get_path_env(char **envp)
{
	int i = 0;

	if (envp == NULL)
		return (NULL);

	while (envp[i])
	{
		/* Check if the line starts with "PATH=" */
		if (strncmp(envp[i], "PATH=", 5) == 0)
		/* Copy everything after the first 5 characters (the prefix) */
			return (strdup(envp[i] + 5));
		i++;
	}
	return (NULL);
}

/**
 * find_path - Locates an executable command in the system PATH.
 * @command: The name of the command to find.
 * @envp: The array of environment variables.
 *
 * Return: Full path to the executable if found, NULL otherwise.
 */

char *find_path(char *command, char **envp)
{
	char *path_copy, *token, *full_path;
	struct stat st;

	if (command == NULL || command[0] == '\0')
		return (NULL);
	/*Get the list of directories from the environment */
	path_copy = get_path_env(envp);
	if (path_copy == NULL)
		return (NULL);
	/*Split the PATH string into tokens using ':' as delimiter */
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		/* Build the absolute path string */
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		/*Check if the constructed path exists on the system*/
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

