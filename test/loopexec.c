#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
  char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
  pid_t child_p;
  int num = 1;

  while (num <= 5)
  {
    child_p = fork();

    if (child_p == -1)
    {
    command = *strtok(input, " ");
      perror("Fork failed");
      exit(EXIT_FAILURE);
    }

    if (child_p == 0)
    {
      execve(argv[0], argv, NULL);
      sleep(4);
    }
    else {
      wait(&child_p);
    }
    num++;
  }
  return (0);
}
