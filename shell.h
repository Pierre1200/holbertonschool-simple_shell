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

/* --- PROTOTYPES DES FONCTIONS --- */

/* Main */
int main(int argc, char **argv, char **envp);

/* parser */
char *read_line(void);
char **split_line(char *line);

/* exec */
int execute_cmd(char **args, char *argv0, char **envp);

/* utils */
void free_array(char **args);

/* Builtin */
int check_builtin(char **args, char *line, char **envp);

/* Path */
char *find_path(char *command, char **envp);

/* Print Error */
void print_error(char *argv0, char *cmd);

#endif

