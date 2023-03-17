#include <stdio.h>

/**
 * main - A programm that prints a line wiith puts function
 *
 * Return: (0) (Success)
 *
 */
int main(void)
{
	char c = 'z';

	while (c >= 'a')
	{
		putchar(c);
		c--;
	}
	putchar('\n');
	return (0);
}
