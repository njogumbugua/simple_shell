#include <stdio.h>
#include <unistd.h>

extern char **environ;  // Declaration of the global variable environ

int main(void)
{
  char *argv[] = {"/bin/ls", "-l"};
  execve(argv[0], argv, environ);
  return 0;
}
