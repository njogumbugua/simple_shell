#include <stdio.h>

char *my_name(char *name)
{
  return (name);
}

int main(void)
{
  char *val = "Njogu Mbugua";
  char *name = my_name(val);
  printf("%s", name);
  return (0);
}
