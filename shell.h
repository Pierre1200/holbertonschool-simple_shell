#ifndef SHELL_H
#define SHELL_H

/* --- BIBLIOTHÈQUES --- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* --- VARIABLES GLOBALES --- */
extern char **environ;

/* --- PROTOTYPES DES FONCTIONS --- */

/* parser */
char *read_line(void);
char **split_line(char *line);

/* exec */
int execute_cmd(char **args, char *argv0);

/* utils */
void free_array(char **args);
void print_error(char *argv0, char *cmd);
int main(int ac, char **av);
int check_builtin(char *command);

#endif
