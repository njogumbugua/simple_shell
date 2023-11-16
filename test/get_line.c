#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 128

char *my_getline(char **lineptr, size_t *n, FILE *stream) {
    // Static variables to retain state between calls
    static char buffer[BUFFER_SIZE];
    static size_t buffer_index = 0;
    static size_t buffer_size = 0;

    // Check if the lineptr and n parameters are valid
    if (lineptr == NULL || n == NULL) {
        errno = EINVAL;
        return NULL;
    }

    // Allocate memory for the line if needed
    if (*lineptr == NULL || *n == 0) {
        *n = BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            errno = ENOMEM;
            return NULL;
        }
    }

    // Loop to read characters until a newline or EOF is encountered
    while (1) {
        // If the buffer is empty, read more characters
        if (buffer_index == buffer_size) {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);

            // Check for end of file
            if (buffer_size == 0) {
                if (*n == 0) {
                    // No characters were read, return NULL
                    return NULL;
                } else {
                    // Return the last line even if it doesn't end with a newline
                    return *lineptr;
                }
            }

            buffer_index = 0;
        }

        // Check for newline character
        if (buffer[buffer_index] == '\n') {
            // Include the newline character in the line
            if (*n <= buffer_size + 1) {
                *n = 2 * (*n);
                *lineptr = realloc(*lineptr, *n);
                if (*lineptr == NULL) {
                    errno = ENOMEM;
                    return NULL;
                }
            }
            (*lineptr)[*n - buffer_size - 2] = '\n';
            (*lineptr)[*n - buffer_size - 1] = '\0';
            buffer_index++;  // Move past the newline character
            break;
        }

        // Append the character to the line
        if (*n <= buffer_size) {
            *n = 2 * (*n);
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL) {
                errno = ENOMEM;
                return NULL;
            }
        }
        (*lineptr)[*n - buffer_size - 1] = buffer[buffer_index];
        buffer_index++;
    }

    return *lineptr;
}

int main() {
    char *line = NULL;
    size_t len = 0;

    // Read lines until NULL is returned (end of file)
    while (my_getline(&line, &len, stdin) != NULL) {
        printf("Line: %s", line);
    }

    // Free memory allocated for the line
    free(line);

    return 0;
}

