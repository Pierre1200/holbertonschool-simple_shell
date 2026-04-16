#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>
#include <sys/stat.h>   /*defines struct stat*/
#include <sys/types.h>  /*often paired with sys/stat.h*/
#include <unistd.h>     /*for stat() on POSIX systems*/

int main(int ac, char **av);
int check_builtin(char *command);
char *find_path(char *command);
extern char **environ;


#endif
