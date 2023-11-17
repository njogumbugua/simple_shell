#include "shell.h"

/**
 * str_len - find string length
 *
 * @str: string to be compared
 *
 * Return: length of string
 */
size_t str_len(const char *str)
{
size_t length = 0;

while (*str != '\0')
{
length++;
str++;
}

return (length);
}

/**
 * str_cat - concatinate two strings
 *
 * @destination: first string
 *
 * @source: second string
 *
 * Return: concatinated string
 */
char *str_cat(char *destination, const char *source)
{
char *ptr = destination;
while (*ptr != '\0')
{
ptr++;
}

while (*source != '\0')
{
*ptr = *source;
ptr++;
source++;
}

*ptr = '\0';

return (destination);
}

/**
 * str_cpy - copy a string to a new location
 *
 * @dest: new destination
 *
 * @src: old destination
 *
 * Return: new copied string
 */
char *str_cpy(char *dest, const char *src)
{
char *original_dest = dest;

while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}

*dest = '\0';

return (original_dest);
}

