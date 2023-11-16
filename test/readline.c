#include <stdio.h>
#include <stdlib.h>

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;  // Invalid arguments
    }

    int capacity = *n;
    int size = 0;
    int c;

    if (*lineptr == NULL) {
        *lineptr = (char *)malloc(capacity);
        if (*lineptr == NULL) {
            return -1;  // Memory allocation failed
        }
    }

    while (1) {
        c = getc(stream);

        if (c == EOF || c == '\n') {
            (*lineptr)[size] = '\0';  // Null-terminate the string
            return size;
        }

        (*lineptr)[size] = (char)c;
        size++;

        if (size >= capacity - 1) {
            capacity *= 2;
            char *new_buffer = (char *)realloc(*lineptr, capacity);

            if (new_buffer == NULL) {
                free(*lineptr);
                return -1;  // Memory reallocation failed
            }

            *lineptr = new_buffer;
            *n = capacity;
        }
    }
}

int main() {
    printf("Enter a line of text: ");
    
    char *line = NULL;
    size_t capacity = 0;
    ssize_t read;

    read = custom_getline(&line, &capacity, stdin);
    
    if (read != -1) {
        printf("You entered: %s\n", line);
    } else {
        fprintf(stderr, "Error reading input\n");
    }

    free(line);

    return 0;
}
