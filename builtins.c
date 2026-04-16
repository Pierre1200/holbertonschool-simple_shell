#include "shell.h"

int check_builtin(char *command)
{
    if (command == NULL)
        return (0);

    if (strcmp(command, "exit\n") == 0)
    {
        free(command);
        exit(0);
    }

    printf("%s: command not found\n", command);
    return (0);
}
