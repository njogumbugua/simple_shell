#include "shell.h"

/**
 * str_cmp - compares two strings
 *
 * @str1: first string
 *
 * @str2: second string
 *
 * Return: result of compared strings
 */
int str_cmp(const char *str1, const char *str2)
{
while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
{
str1++;
str2++;
}
return (*str1 - *str2);
}
