#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
    // Get the current PATH
    char *path = NULL;
    path = getenv("PATH");

    if (path == NULL) {
        fprintf(stderr, "Error: Unable to retrieve PATH\n");
        return 1;
    }

    // Tokenize the PATH to get individual directories
    char *token = strtok(path, ":");
    while (token != NULL) {
        // Open the directory
        DIR *dir = opendir(token);

        if (dir == NULL) {
            fprintf(stderr, "Error: Unable to open directory %s\n", token);
        } else {
            // Read the contents of the directory
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                // Print the name of each file in the directory
                if (entry->d_type == DT_REG) {
                    printf("%s/%s\n", token, entry->d_name);
                }
            }

            // Close the directory
            closedir(dir);
        }

        // Get the next directory from the PATH
        token = strtok(NULL, ":");
    }

    return 0;
}

