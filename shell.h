#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void tokenize(char *commands);
void prompt_display();
#endif
