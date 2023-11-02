#include "shell.h"
#include <stdio.h>

void dispay_prompt()
{
  size_t n = 10;/*arbitrary length*/
  char *buf = NULL;

  printf("$ ");
  getline(&buf, &n, stdin);
  printf("%s", buf);/*printf is for debugging purposes*/
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
