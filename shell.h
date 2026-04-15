#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int ac, char **av);
int check_builtin(char *command);


#endif