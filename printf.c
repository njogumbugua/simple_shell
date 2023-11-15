#include "shell.h"

void print_f(const char *format, ...)
{
  va_list args;
  char buffer[1024];
  int length;
  va_start(args, format);

  length = vsnprintf(buffer, sizeof(buffer), format, args);

  va_end(args);

  if (length >= 0)
  {
      write(STDOUT_FILENO, buffer, length);
  }
}
