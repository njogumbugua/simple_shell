#include "shell.h"

/**
 * handle_path - handle path env
 *
 * @commands: tokenized commands
 *
 * @path: path environment variable
 */
void handle_path(char **commands, char *path)
{
char *token = strtok(path, ":");

while (token != NULL)
{
char *full_path =
malloc(str_len(token) + str_len("/") + str_len(commands[0]) + 1);
str_cpy(full_path, token);
str_cat(full_path, "/");
str_cat(full_path, commands[0]);

if (file_exists(full_path))
{
execve(full_path, commands, NULL);
}
free(full_path);
token = strtok(NULL, ":");
}
print_f("command not found: %s\n", commands[0]);
exit(EXIT_FAILURE);
}
