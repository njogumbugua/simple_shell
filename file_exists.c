#include "shell.h"

/**
 * file_exists - check if file command exists
 *
 * @path: command to be verified
 *
 * Return: true if command exists else false
 */
bool file_exists(const char *path)
{
if (access(path, F_OK) != -1)
{
return (true);
}
return (false);
}
