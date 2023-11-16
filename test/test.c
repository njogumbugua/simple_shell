#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

  void tokenize(char *commands)
{
  char *pCommands = strtok(commands, " ");

  while(pCommands != NULL) 
  {
      printf("%s\n", pCommands);/*printf is for debugging purposes*/
      pCommands = strtok(NULL, " ");
  }
}
int main(int argc, char *argv[])
{
  char string[] = "Hi how are you";
  tokenize(string);


  return EXIT_SUCCESS;
}
