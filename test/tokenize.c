#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to tokenize a string
char** tokenizeString(char* inputString, const char* delimiter, int* tokenCount)
{
    // Copy the input string because strtok modifies the original string
    char* inputCopy = strdup(inputString);
    
    // Tokenize the string using strtok
    char* token = strtok(inputCopy, delimiter);
    int count = 0;

    // Count the number of tokens
    while (token != NULL) {
        count++;
        token = strtok(NULL, delimiter);
    }

    // Allocate memory for an array of strings
    char** tokens = (char**)malloc(count * sizeof(char*));

    // Tokenize the string again and store each token in the array
    token = strtok(inputString, delimiter);
    for (int i = 0; i < count; i++) {
        tokens[i] = strdup(token);
        token = strtok(NULL, delimiter);
    }

    // Update the tokenCount pointer with the number of tokens
    *tokenCount = count;

    // Free the memory allocated for the copied string
    free(inputCopy);

    // Return the array of tokens
    return tokens;
}

int main() {
    char input[] = "This is a sample sentence";
    const char delimiter[] = " ";

    int tokenCount;
    char** tokens = tokenizeString(input, delimiter, &tokenCount);

    printf("Number of tokens: %d\n", tokenCount);
    for (int i = 0; i < tokenCount; i++) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        // Don't forget to free the memory allocated for each token
        free(tokens[i]);
    }

    // Free the memory allocated for the array of tokens
    free(tokens);

    return 0;
}

