#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void prompt_display();
void tokenize(char *commands);
#endif
