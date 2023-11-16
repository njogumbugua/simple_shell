#include <stdio.h>
#include <string.h>

int main(void)
{
  char str1[] = "This is a string.";
  char str2[] = "This is a string.";

  int compare = strcmp(str1, str2);
  if (compare == 0)
  {
    printf("Strings are equal\n");
  }else {
    printf("Strings are not equal\n");
  }

  return (0);
}
