#include "main.h"

/**
 * rev_string - prints a string
 * @s: the string
 *
 * Return: print the string in reverse
 */
void rev_string(char *s)
{
	int len = 0;
	int i;

	while (s[len] != '\0')
	{
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		*s[i];
	}
}
