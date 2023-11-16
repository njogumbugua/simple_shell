#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char str[80] = "Hi my name is njogu";
  char *token;
   
  char *string = malloc(sizeof(char));
   /* get the first token */
   token = strtok(str, " ");
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, " ");
   }
   
  return (0);
}
