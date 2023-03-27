#include "main.h"

/**
 * _puts - prints a string
 * @str: the string
 *
 * Return: the length of the string
 */
void _puts(char *str)
{
char c;

while ((c = *str++) != '\0')
{
_putchar(&c);
}
_putchar ("\n");
}
