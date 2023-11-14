#include "shell.h"

int main()
{
  char *input;
  char **commands;
  char *prompt = "$ ";

while (1)
  {
    if (isatty(STDIN_FILENO))
    {
      write(STDOUT_FILENO, prompt, 2);
    }
    input = read_commands();

    if (str_cmp(input, "exit") == 0)
    {
      break;
    }
    
    commands = tokenize_commands(input);
    execute_commands(commands);

    free(input);
    free(commands);
  }

  return(0);
}
