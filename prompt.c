#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void start_shell()
{
  char *line;
  char **commands;
  while (1)
  {
    printf("$ ");
    line = read_commands();
    commands = tokenize_commands(line);
    execute_commands(commands);

    free(line);
    free(commands);
  }
}

char *read_commands()
{
  char *line = NULL;
  size_t bufsize = 0;

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    } else  {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }

  return (line);
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **tokenize_commands(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return (tokens);
}

int execute_commands(char **commands)
{
  pid_t pid;

  pid = fork();
  if (pid == 0) {
    if (execvp(commands[0], commands) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid != 0) {

    perror("lsh");
  } else {
    wait(NULL);
  }

  return (1);
}



