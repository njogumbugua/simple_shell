#include "shell.h"

char **search_path(char *path)
{
  int bufsize = TOKEN_BUFSIZE, position = 0;
  char *token;
  char **tokens = malloc(bufsize * sizeof(char*));

  path = getenv("PATH");

  if (path == NULL) {
      perror("Error");
  }


  token = strtok(path, ":");

  while (token != NULL) {
    tokens[position] = token;
    position++;
    token = strtok(NULL, ":");
  }

  return(tokens);
}
