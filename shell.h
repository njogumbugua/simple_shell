#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void start_shell(void);
char *read_commands();
char **tokenize_commands(char *line);
void prompt_display(void);
int execute_commands(char **commands);
#endif
