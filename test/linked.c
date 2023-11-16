#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
struct Node {
  char directory[256];
  struct Node *next;
};

// Function to add a new node to the linked list
struct Node *addNode(struct Node *head, const char *directory) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  // Copy the directory into the new node
  strncpy(newNode->directory, directory, sizeof(newNode->directory) - 1);
  newNode->directory[sizeof(newNode->directory) - 1] = '\0';

  // Set the next pointer of the new node to the current head
  newNode->next = head;

  // Update the head of the linked list
  return newNode;
}

// Function to print the linked list
void printList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%s\n", current->directory);
    current = current->next;
  }
}

int main() {
  // Get the PATH environment variable
  const char *path = getenv("PATH");

  // If PATH is not set, print an error and exit
  if (path == NULL) {
    fprintf(stderr, "PATH environment variable not set\n");
    return EXIT_FAILURE;
  }

  // Initialize the linked list
  struct Node *head = NULL;

  // Tokenize the PATH variable using ':' as the delimiter
  char *token = strtok((char *)path, ":");
  while (token != NULL) {
    // Add each directory to the linked list
    head = addNode(head, token);

    // Get the next token
    token = strtok(NULL, ":");
  }

  // Print the linked list
  printf("List of PATH directories:\n");
  printList(head);

  // Free the memory allocated for the linked list
  struct Node *current = head;
  while (current != NULL) {
    struct Node *next = current->next;
    free(current);
    current = next;
  }

  return EXIT_SUCCESS;
}
