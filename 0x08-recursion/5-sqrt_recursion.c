#include "main.h"
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer to find sqrt of
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
if (n < 0)
{
return (-1);
}
else if (n == 0 || n == 1)
{
return (n);
}
else
{
int i = 1;
while (i * i <= n)
{
i++;
}
i--;
if (i *i == n)
{
return (i);
}
else
{
return (_sqrt_recursion(n - 1));
}
}
}

