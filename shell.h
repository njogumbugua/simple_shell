#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

void start_shell(void);
char *read_commands();
char **tokenize_commands(char *line);
int execute_commands(char **commands);
#endif
