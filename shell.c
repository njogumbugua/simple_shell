#include "shell.h"

/**
 * main - start of function
 *
 * Return: 0 on success
 */
int main(void)
{
char *input;
char **commands;
char *prompt = "$ ";

while (1)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, prompt, 2);
}
input = read_commands();

if (str_cmp(input, "exit") == 0)
{
break;
}

if (str_cmp(input, "env") == 0)
{
print_environment();
}

commands = tokenize_commands(input);
execute_commands(commands);

free(input);
free(commands);
}

return (0);
}
