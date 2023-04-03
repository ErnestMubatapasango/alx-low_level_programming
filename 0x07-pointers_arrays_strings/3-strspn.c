#include "main.h"

/**
 * _strspn - a function that gets the length of a prefix substring
 *
 * @s: the initial segment of
 *
 * @accept: which consist only of bytes from
 *
 * Return: the number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int len = 0;
char *p;

for (; *s != '\0'; s++)
{
for (p = accept; *p != '\0'; p++)
{
if (*s == *p)
{
break;
}
}
if (*p == '\0')
{
return (len);
}
len++;
}
return (len);
}

