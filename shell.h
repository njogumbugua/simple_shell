#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t \r \n \a"

extern char **environ;

char *read_commands();
char **tokenize_commands(char *line);
int execute_commands(char **command);
int change_dir(char **args);
int file_exists(const char *filename);
int exit_shell();
char **search_path(char *path);

#endif
