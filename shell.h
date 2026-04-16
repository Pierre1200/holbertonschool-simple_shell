#ifndef SHELL_H
#define SHELL_H

/* --- BIBLIOTHÈQUES --- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*for stat() on POSIX systems*/
#include <string.h>
#include <sys/types.h> /*often paired with sys/stat.h*/
#include <sys/wait.h>
#include <sys/stat.h> /*defines struct stat*/

/* --- VARIABLES GLOBALES --- */
extern char **environ;

/* --- PROTOTYPES DES FONCTIONS --- */

/* Main */
int main(int ac, char **av);

/* parser */
char *read_line(void);
char **split_line(char *line);

/* exec */
int execute_cmd(char **args, char *argv0);

/* utils */
void free_array(char **args);

/* Builtin */
int check_builtin(char *command);

/* Path */
char *find_path(char *command);

#endif

