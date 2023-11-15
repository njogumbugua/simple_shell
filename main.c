char *input;
char **commands;
char *prompt = "$ ";

<<<<<<< HEAD
while (1)
{
if (isatty(STDIN_FILENO))
=======
int main(void)
>>>>>>> 05f5d2861b4c9a05cd47d93a70dbf3cceec387b7
{
write(STDOUT_FILENO, prompt, 2);
}
input = read_commands();

<<<<<<< HEAD
if (str_cmp(input, "exit") == 0)
{
break;
}

commands = tokenize_commands(input);
execute_commands(commands);
=======
  while (1) {
    if (isatty(STDIN_FILENO)) {
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
>>>>>>> 05f5d2861b4c9a05cd47d93a70dbf3cceec387b7

free(input);
free(commands);
}

<<<<<<< HEAD
return(0);
=======
  return (0);
>>>>>>> 05f5d2861b4c9a05cd47d93a70dbf3cceec387b7
}
