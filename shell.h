#ifndef SHELL_H
#define SHELL_H

/* Standard C Library Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* POSIX and System Call Includes */
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* ========================================================================= */
/* FUNCTION PROTOTYPES                             */
/* ========================================================================= */

/* Core (main.c) */
int main(int argc, char **argv, char **envp);

/* Parsing (parser.c) */
char *read_line(void);
char **split_line(char *line);

/* Execution (executor.c) */
int execute_cmd(char **args, char *argv0, char **envp);

/* Built-in Commands (builtins.c) */
int check_builtin(char **args, char *line, char **envp);

/* Path */
char *get_path_env(char **envp);
char *find_path(char *command, char **envp);

/* Utilities and Error Handling (utils.c) */
void free_array(char **args);
void print_error(char *argv0, char *cmd);

#endif
