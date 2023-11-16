#include <unistd.h>

extern char **environ;

void print_environment() {
    char **env_var = environ;

    while (*env_var != NULL) {
        size_t len = 0;
        while ((*env_var)[len] != '\0') {
            len++;
        }
        write(STDOUT_FILENO, *env_var, len);
        write(STDOUT_FILENO, "\n", 1);
        env_var++;
    }
}

int main() {
    char *message = "Current environment:\n";
    write(STDOUT_FILENO, message, 20);  // Using write for printing the message
    print_environment();

    return 0;
}

