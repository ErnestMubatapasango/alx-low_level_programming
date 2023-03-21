#include "main.h"
/**
* print_alphabet_x10 - prints 10 times the alphabet
*
* Return: Always 0.
*/
void print_alphabet_x10(void)
{
char c;
int x = 0;

while (x < 10)
{
for (c = 'a'; c <= 'z'; c++)
{
_putchar(c);
}
x++;
_putchar('\n');
}
}
