#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prompt_display()
{
  size_t bufsize = 10;
  char *buffer;
  int value;

  buffer = malloc(sizeof(char) * bufsize);
  value = getline(&buffer,  &bufsize, stdin);
  if (value == -1)
  {
    exit(-1);
  }
  printf("%s", buffer);
}

int main(void)
{
  while (1)
  {
    prompt_display();
  }
  return (0);
}
