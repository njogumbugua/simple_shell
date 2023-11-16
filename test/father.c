#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num_children = 0;

  while (num_children < 5)
  {
    pid_t process;
        pid_t child_pid = fork();
    process = getpid();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(1);
        } else if (child_pid == 0) {
            // This is the child process
            printf("Child %d executing ls -l /tmp:\n",process);
            execl("/bin/ls", "ls", "-l", "/tmp", NULL);
      sleep(2);
            // If execl() fails, it will continue from here
            perror("execl failed");
            exit(1);
        } else {
            // This is the parent process
      wait(&child_pid);
        }
    num_children++;
    }
    return 0;
}
