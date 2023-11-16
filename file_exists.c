#include "shell.h"
bool file_exists(const char *path)
{
if (access(path, F_OK) != -1)
{
return (true);
}
return (false);
}
