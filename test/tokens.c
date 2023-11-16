#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to tokenize a string and print the tokens
void tokenizeAndPrint(char* inputString, const char* delimiter) {
    // Copy the input string because strtok modifies the original string
    char* inputCopy = strdup(inputString);
    
    // Tokenize the string using strtok
    char* token = strtok(inputCopy, delimiter);

    // Print the tokens
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiter);
    }

    // Free the memory allocated for the copied string
    free(inputCopy);
}

int main() {
    char input[] = "This is a sample sentence";
    const char delimiter[] = " ";

    printf("Original string: %s\n", input);
    printf("Tokens:\n");
    
    tokenizeAndPrint(input, delimiter);

    return 0;
}

