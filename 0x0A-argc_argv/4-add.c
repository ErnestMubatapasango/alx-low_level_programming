#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers.
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i, x, add = 0;
	char *s;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; argv[i]; i++)
	{
		x = strtol(argv[i], &s, 10);
		if (*s)
		{
			printf("Error\n");
			return (1);
		}
		else
		{
			add += x;
		}
	}
	printf("%d\n", add);

	return (0);
}
