#include "main.h"
/**
 * _puts_recursion - print a string
 * @s:string
 * Return:void
 */
void _puts_recursion(char *s)
{
	s[20] = "What is up";
	int i;

	for (i = 0; i < s; i++)
	{
		_putchar([i]);
		_puts_recursion(i);
	}
	_putchar('\n');
}
