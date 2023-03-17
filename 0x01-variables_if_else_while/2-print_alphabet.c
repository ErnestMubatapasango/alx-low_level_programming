#include <stdio.h>
#include <stdlib.h>
/**
 * main - A programm that prints a line wiith puts function
 *
 * Return: (0) (Success)
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
