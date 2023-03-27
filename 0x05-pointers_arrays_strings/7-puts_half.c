#include "main.h"
/**
 * puts_half - prints every other character of a string
 *
 * @str: char to check
 *
 * Return: 0 is success
 */
void puts_half(char *str)
{
	int len = 0;
	int start = len / 2;
	int i;

	while (*str != '\0')
	{
	str++;
	len++;
	}
	if (len % 2 != 0)
	{
	start = (len - 1) / 2;
	}
	for (i = start; i < len; i++)
	{
	_putchar(str[i]);
	}
	_putchar('\n');
}
