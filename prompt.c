#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char *read_commands()
{
  char *input = NULL;
  int i;
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

  i = 0;
  while (input[i])
  {
    if (input[i] == '\n')
    {
      input[i] = '\0';
    }
    i++;
  }

  if (strcmp(input, "exit") == 0)
  {
    exit(EXIT_SUCCESS);
  }

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
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += TOKEN_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens)
      {
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
  char *envp[1];
  int i;

  if(!file_exists(*commands))
  {
    perror("error");
  }
  for (i = 0; commands[i] != NULL; i++)
  {
    pid = fork();
    envp[0] = NULL;
    if (pid == 0)
    {
      execve(commands[i], commands, envp);

    } else if (pid != 0) {
      wait(&pid);
    }
  }


  return (1);
}


