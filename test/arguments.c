#include <stdio.h>

int main(int argc, char *argv[])
{
  int arguments = 1;

  while (argv[arguments] != NULL)
  {
    printf("%s\n", argv[arguments]);
    arguments++;
  }
  return (0);
}
