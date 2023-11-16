#include "shell.h"

void print_environment()
{
  char **env_var = environ;

  while (*env_var != NULL)
  {
    size_t len = 0;
    while ((*env_var)[len] != '\0')
    {
      len++;
    }
    write(STDOUT_FILENO, *env_var, len);
    write(STDOUT_FILENO, "\n", 1);
    env_var++;
  }
}
