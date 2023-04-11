#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to a newly allocated space in memory which
 * contains the contents of s1, followed by the contents of s2,
 * and null terminated. NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
size_t len1, len2, i;
char *result;

if (s1 == NULL)
{
s1 = "";
}
if (s2 == NULL)
{
s2 = "";
}
len1 = 0;
while (s1[len1] != '\0')
{
len1++;
}
len2 = 0;
while (s2[len2] != '\0')
{
len2++;
}
result = malloc((len1 + len2 + 1) * sizeof(char));
if (result == NULL)
{
return (NULL);
}
for (i = 0; i < len1; i++)
{
result[i] = s1[i];
}
for (j = 0; j < len2; j++)
{
result[i++] = s2[j];
}
result[i] = '\0';
return (result);
}

