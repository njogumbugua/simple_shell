#include "shell.h"

/**
 * handle_path - handle path env
 *
 * @command: tokenized commands
 *
 */

char *handle_path(const char *command)
{
char *path_copy;
char *path = getenv("PATH");
char *token;
char *full_path;

if (path == NULL)
{
perror("getenv");
exit(EXIT_FAILURE);
}
path_copy = strdup(path);
token = strtok(path_copy, ":");
full_path = NULL;

while (token != NULL)
{
full_path = malloc(strlen(token) + strlen("/") + strlen(command) + 1);
if (full_path == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

strcpy(full_path, token);
strcat(full_path, "/");
strcat(full_path, command);

if (file_exists(full_path))
{
free(path_copy);
return (full_path);
}
free(full_path);
full_path = NULL;
token = strtok(NULL, ":");
}
free(path_copy);
return strdup(command);
}
