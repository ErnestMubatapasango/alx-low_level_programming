#include <stdio.h>

/**
 * main - A programm that prints a line wiith puts function
 *
 * Return: (0) (Success)
 */
int main(void)
{
	int a;

	for (a = 48; a < 58; a++)
	{
		putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}
