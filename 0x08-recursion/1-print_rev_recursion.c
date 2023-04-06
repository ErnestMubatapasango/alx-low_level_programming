#include "main.h"
/**
* _print_rev_recursion -> printing a string in reverse
* @s: the string to be printed in rev
*/
void _print_rev_recursion(char *s)
{
int len, i;

if (*s == '\0')
{
return;
}
_print_rev_recursion(s + 1);
_putchar(*s);
}

