#include "shell.h"

/**
 * file_exists - check if file command exists
 *
 * @path: command to be verified
 *
 * Return: true if command exists else false
 */
int file_exists(const char *path)
{
return (access(path, F_OK) != -1);
}
