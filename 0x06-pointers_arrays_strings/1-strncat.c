#include "main.h"
#include <stdio.h>
/**
 * _strncat - concatenates two strings
 *
 * @src: The source of strings
 * @dest: The destination of the string
 * @n: The length of int
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
char *dest_ptr = dest;
while (*dest_ptr != '\0')
{
dest_ptr++;
}
while (i < n && *src != '\0')
{
*dest_ptr = *src;
dest_ptr++;
src++;
i++;
}
*dest_ptr = '\0';
return (dest);
}
