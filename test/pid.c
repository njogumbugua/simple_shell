#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
  pid_t parent_pid;
  pid_t my_pid;

  parent_pid = getppid();
  my_pid = getpid();

  printf("Process ID: %u\n", parent_pid);
  printf("Process ID: %u\n", my_pid);
  return (0);
}
