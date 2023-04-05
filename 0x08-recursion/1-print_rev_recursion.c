#include "main.h"
/**
* _print_rev_recursion -> printing a string in reverse
* @s: the string to be printed in rev
*/
void _print_rev_recursion(char *s)
{
int len, i;

while (s[len] != '\0')
{
len++;
}
for (; i >= 0; i--)
{
_putchar(s[i]);
}
_putchar('\n');
}

