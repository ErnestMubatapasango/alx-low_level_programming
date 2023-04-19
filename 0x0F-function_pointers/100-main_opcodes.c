#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success 1 if wrong number of arguments 2 if negative number
 */
int main(int argc, char *argv[])
{
int num_bytes, i;
char *main_addr = (char *)main;

if (argc != 2)
{
printf("Error\n");
return (1);
}

num_bytes = atoi(argv[1]);
if (num_bytes < 0)
{
printf("Error\n");
return (2);
}

for (i = 0; i < num_bytes; i++)
printf("%02hhx ", main_addr[i]);

printf("\n");
return (0);
}

