#include <stdio.h>
/**
 * main - prints all single digit numbers of base
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i < 10)
	{
		putchar((i % 10) + '0');
		if (i <= 9)
		{
			putchar(',');
			putchar(' ');
		}
		i++;
	}
	putchar('\n');
	return (0);
}
