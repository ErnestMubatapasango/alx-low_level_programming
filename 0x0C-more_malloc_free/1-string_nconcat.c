#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - a function that concatenates two strings.
 *
 * @s1: first char
 * @s2: secound char
 * @n: unsigned int
 *
 * Return: If the function fails, it should return NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int s1_len = 0, s2_len = 0;
char *concat_str;
unsigned int i = 0, j = 0;

if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

while (s1[s1_len] != '\0')
s1_len++;

while (s2[s2_len] != '\0')
s2_len++;

if (n >= s2_len)
n = s2_len;

concat_str = malloc((s1_len + n + 1) * sizeof(char));
if (concat_str == NULL)
return (NULL);

for (i = 0; i < s1_len; i++)
concat_str[i] = s1[i];

for (j = 0; j < n; j++, i++)
concat_str[i] = s2[j];

concat_str[i] = '\0';

return (concat_str);
}

