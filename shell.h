#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void display_prompt();
void tokenize(char *commands);
#endif
