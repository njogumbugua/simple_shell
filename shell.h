#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

void start_shell(void);
char *read_commands();
char **tokenize_commands(char *line);
int execute_commands(char **commands);
int change_dir(char **args);
int exit_shell();
#endif
