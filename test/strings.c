#include "shell.h"

size_t str_len(const char *str)
{
  size_t length = 0;

  while (*str != '\0') {
    length++;
    str++;
  }

  return (length);
}

char *str_cat(char *destination, const char *source)
{
    char *ptr = destination;
    while (*ptr != '\0') 
  {
        ptr++;
    }

    while (*source != '\0') {
        *ptr = *source;
        ptr++;
        source++;
    }

    *ptr = '\0';

    return (destination);
}

char* str_cpy(char *dest, const char *src)
{
    char *original_dest = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return (original_dest);
}

