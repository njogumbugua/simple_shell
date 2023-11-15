#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

<<<<<<< HEAD
void start_shell()
{
<<<<<<< HEAD
char *input;
char **commands;

while (1)
{
printf("$ ");
input = read_commands();
commands = tokenize_commands(input);
execute_commands(commands);

free(input);
free(commands);
}
=======
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
>>>>>>> c111305a3b940e238407ffd46a76cc870698852b
}
=======
>>>>>>> e411b18445ac18323938ef9c8fda602a908dabb6

char *read_commands()
{
<<<<<<< HEAD
char *input = NULL;
size_t bufsize = 0;

if (getline(&input, &bufsize, stdin) == -1){
if (feof(stdin)) {
exit(EXIT_SUCCESS);
} else  {
perror("readline");
exit(EXIT_FAILURE);
}
}

return (input);
=======
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
>>>>>>> c111305a3b940e238407ffd46a76cc870698852b
}

char **tokenize_commands(char *line)
{
<<<<<<< HEAD
int bufsize = LSH_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char*));
char *token;

if (!tokens) {
fprintf(stderr, "allocation error\n");
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
fprintf(stderr, " allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, LSH_TOK_DELIM);
}
tokens[position] = NULL;
return (tokens);
=======
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
>>>>>>> c111305a3b940e238407ffd46a76cc870698852b
}

int execute_commands(char **commands)
{
<<<<<<< HEAD
pid_t pid;
=======
  pid_t pid;
  int i;
  for (i = 0; commands[i] != NULL; i++)
  {
    pid = fork();
    if (pid == 0)
    {
      char *path = getenv("PATH");
      handle_path(commands + i, path);
      exit(EXIT_FAILURE);
    } else if (pid != 0)
    {
      wait(&pid);
    }
  }
  return (1);
}
>>>>>>> c111305a3b940e238407ffd46a76cc870698852b

pid = fork();
if (pid == 0)
{
char *args[2];
char *envp[1];

<<<<<<< HEAD
args[0] = *commands;
args[1] = NULL;
envp[0] = NULL;

if (execve(args[0], args, envp) == -1)
{
perror("Error");
}
exit(EXIT_FAILURE);
} else if (pid != 0) 
{
wait(&pid);
}

return (1);
}
=======
>>>>>>> c111305a3b940e238407ffd46a76cc870698852b
