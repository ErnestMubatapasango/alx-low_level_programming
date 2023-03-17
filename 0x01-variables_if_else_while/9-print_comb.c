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
		putchar(i + '0');
		if (i == 9)
		{
			continue;
			putchar(',');
			putchar(' ');
		}
		i++;
	}
	return (0);
}
