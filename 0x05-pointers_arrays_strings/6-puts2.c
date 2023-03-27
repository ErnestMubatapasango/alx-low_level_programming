#include "main.h"
/**
 * puts2 - print every character of a string
 * _putchar - print each character
 * @str: char to check
 *
 * Description: This will reverse a string
 * Return: 0 is success
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
