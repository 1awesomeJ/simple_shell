#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
extern char **environ;
void _print_env(char **env);
char * _getenv(char *name);
char *_strcat(char *dest, char *src);
char* findpath(char *cmnd);

#endif
