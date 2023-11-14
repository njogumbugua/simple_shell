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

  return (input);
}

char **tokenize_commands(char *line)
{
  int bufsize = TOKEN_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens)
  {
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
  int i;

  for (i = 0; commands[i] != NULL; i++)
  {
    pid = fork();
    if (pid == 0)
    {
      char *path = getenv("PATH");
      char *token = strtok(path, ":");

      while (token != NULL)
      {
        char *full_path = malloc(strlen(token) + strlen("/") + strlen(commands[i]) + 1);
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, commands[i]);

        if (file_exists(full_path))
        {
          execve(full_path, commands, NULL);
        }

          free(full_path);
          token = strtok(NULL, ":");
      }
      exit(EXIT_FAILURE);
    } else if (pid != 0)
    {
      wait(&pid);
    }
  }
  return (1);
}


