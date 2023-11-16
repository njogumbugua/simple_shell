#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *get_env = getenv("PATH");

  if (get_env == NULL)
  {
    perror("PATH");
    exit(EXIT_FAILURE);
  }

  char *duplicate = strdup(get_env);

  if (duplicate == NULL)
  {
    perror("Memmory allocation failed");
    exit(EXIT_FAILURE);
  }

  char *token = strtok(duplicate, ":");

  while (token != NULL)
  {
    printf("%s\n", token);
    token = strtok(NULL, ":");
  }
  return EXIT_SUCCESS;
}
