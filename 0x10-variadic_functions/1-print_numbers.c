#include "variadic_functions.h"

/**
 * print_numbers - prints numbers followed by a new line
 * @n: number of parameter
 * @separator: separator between two numbers
 * Return: Always 0
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list args;
va_start(args, n);
unsigned int i;

for (i = 0; i < n; i++)
{
int num = va_arg(args, int);
printf("%d", num);

if (separator != NULL && i < n - 1)
{
printf("%s", separator);
}
}

va_end(args);
printf("\n");
}

