#include "shell.h"

char *builtin_str[] = {
  "cd",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &change_dir,
  &exit_shell
};

int builtins_size() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int change_dir(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return (1);
}


int exit_shell()
{
  return 0;
}

int execute_builtins(char **commands)
{
  int i;

  if (commands[0] == NULL) {
    return (1);
  }

  for (i = 0; i < builtins_size(); i++) {
    if (strcmp(commands[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(commands);
    }
  }

  return execute_commands(commands);
}
