#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

void prompt_display()
{
  size_t n = 10;/*arbitrary length*/
  char *buf = malloc(sizeof(size_t)*n);

  printf("$ ");
  getline(&buf, &n, stdin);
  tokenize(buf);
}


void tokenize(char *commands)
{
  char *pCommands = strtok(commands, " ");

  while(pCommands != NULL) 
  {
    printf("%s\n", pCommands);/*printf is for debugging purposes*/
    pCommands = strtok(NULL, " ");
  }
}

