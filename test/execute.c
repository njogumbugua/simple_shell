#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main(void) {
    char *input = NULL;
    size_t input_size = 0;
    char *command;

    while (1) {
        printf("Super Simple Shell > ");
        if (getline(&input, &input_size, stdin) == -1) {
            perror("Error reading input");
            break;
        }

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Exit the shell if the user enters "exit"
    if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Fork a child process to execute the command
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            // This code is executed by the child process
            command = strtok(input, " ");
            if (command != NULL) {
                char *args[] = {command, NULL};
                char *envp[] = {NULL};

                // Execute the command with its full path using execve
                if (execve(command, args, envp) == -1) {
                    perror("Exec failed");
                    exit(EXIT_FAILURE);
                }
            } else {
                printf("Please enter a valid command.\n");
            }

            // The child process should exit after executing the command
            exit(EXIT_SUCCESS);
        } else {
            // This code is executed by the parent process
            int status;
            waitpid(child_pid, &status, 0);

            if (WIFEXITED(status)) {
                // Child process exited normally
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            } else {
                perror("Child process did not exit normally");
            }
        }
    }

    free(input); // Free the dynamically allocated input buffer
    return 0;
}

