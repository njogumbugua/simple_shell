#include "shell.h"

/**
 * read_commands - read input from user
 *
 * Return: input from user
 */
char *read_commands()
{
char *input = NULL;
size_t bufsize = 0;
ssize_t bytes;

bytes = getline(&input, &bufsize, stdin);
if (bytes == -1)
{
if (feof(stdin))
{
free(input);
exit(EXIT_SUCCESS);
}
else
{
perror("readline");
exit(EXIT_FAILURE);
}
}
if (input[bytes - 1] == '\n')
{
input[bytes - 1] = '\0';
}
return (input);
}

/**
 * tokenize_commands - tokenize user input
 *
 * @line: input from user
 *
 * Return: tokenized user input
 */
char **tokenize_commands(char *line)
{
int bufsize = TOKEN_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("allocation error\n");
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
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, TOKEN_DELIM);
}
tokens[position] = NULL;
return (tokens);
}

/**
 * execute_commands - execute input from user
 *
 * @commands: tokenized user input
 *
 * Return: 1 on success;
 */
int execute_commands(char **commands)
{
int i;
pid_t pid;
char *full_path;

for (i = 0; commands[i] != NULL; i++)
{
full_path = handle_path(commands[i]);

if (full_path == NULL)
{
fprintf(stderr, "Command '%s' not found\n", commands[i]);
continue;
}

pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execve(full_path, commands, NULL);
perror("execve");

exit(EXIT_FAILURE);
}
else
{
waitpid(pid, NULL, 0);

free(full_path);
}
}

return (1);
}

