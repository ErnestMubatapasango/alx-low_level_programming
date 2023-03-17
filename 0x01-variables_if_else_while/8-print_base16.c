#include <stdio.h>

/**
 * main - A programm that prints a line wiith puts function
 *
 * Return: (0) (Success)
 */
int main(void)
{
	char c = '0';

	while (c <= '9')
	{
		putchar(c);
		c++;
	}

	c = 'a';

	while (c <= 'f')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
