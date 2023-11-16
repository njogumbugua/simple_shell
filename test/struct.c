#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  struct stat st;

  if (argc < 2)
  {
    printf("Usage: %s path_to_file ...\n", argv[0]);
    return (1);
  }

  int size = 1;
  while (argv[size] != NULL)
  {
    if (stat(argv[size], &st) == 0)
    {
      printf("FILE FOUND\n");
    } else {
      printf("FILE NOT FOUND\n");
    }
    size++;
  }
  return (0);
}
