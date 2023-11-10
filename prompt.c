#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void start_shell()
{
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
}

char *read_commands()
{
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
}

char **tokenize_commands(char *line)
{
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
}

int execute_commands(char **commands)
{
pid_t pid;

pid = fork();
if (pid == 0)
{
char *args[2];
char *envp[1];

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
