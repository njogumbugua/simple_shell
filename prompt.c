#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void start_shell()
{
  char *input;
  char **commands;
  char *prompt = "$ ";

  while (1)
  {
    write(STDOUT_FILENO, prompt, 2);
    input = read_commands();
    commands = tokenize_commands(input);
    execute_commands(commands);

    free(input);
    free(commands);
  }
}

char *read_commands()
{
  char *input = NULL;
  size_t bufsize = 0;
  int bytes;
  bytes = getline(&input, &bufsize, stdin);

  if ( bytes == -1)
  {
    if (feof(stdin))
    {
      exit(EXIT_SUCCESS);
    } else {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }
  if (input[bytes - 1] == '\n')
    input[bytes - 1] = '\0';

  return (input);
}

char **tokenize_commands(char *line)
{
  int bufsize = TOKEN_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    perror("allocation error");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, TOKEN_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += TOKEN_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        perror("allocation error");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKEN_DELIM);
  }
  tokens[position] = NULL;
  return (tokens);
}

int execute_commands(char **commands)
{
  pid_t pid;

  pid = fork();
  if (pid == 0)
  {
      char *args[2];
      char *envp[2];

    args[0] = *commands;
    args[1] = NULL;
    envp[0] = "PATH=/bin";
    envp[1] = NULL;

    if (execve(args[0], args, envp) == -1)
    {
      perror("Error");
    }
    exit(EXIT_FAILURE);
  } else if (pid != 0) {
    wait(&pid);
  }

  return (1);
}


