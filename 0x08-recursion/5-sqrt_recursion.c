#include "main.h"

/**
 * _sqrt_helper - checks to see if number is prime
 * @n:int
 * @min:int
 * @max:int
 * Return:int
 */
int _sqrt_helper(int n, int min, int max)
{
int mid = (min + max) / 2;
if (min > max)
{
return (-1);
}
else if (mid * mid == n)
{
return (mid);
}
else if (mid * mid > n)
{
return (_sqrt_helper(n, min, mid - 1));
}
else
{
return (_sqrt_helper(n, mid + 1, max));
}
}

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

