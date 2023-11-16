#include "shell.h"

void customPutchar(char c)
{
    write(STDOUT_FILENO, &c, 2);
}
