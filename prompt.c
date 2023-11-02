#include "shell.h"
#include <stdio.h>

void prompt_display()
{
  size_t n = 10;/*arbitrary length*/
  char *buf = NULL;

  printf("$ ");
  getline(&buf, &n, stdin);
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

