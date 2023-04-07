#include "main.h"

/**
 * is_prime_helper - checks to see if number is prime
 * @n:int
 * @d:int
 * Return:int
 */
int is_prime_helper(int n, int d)
{
if (d == n)
{
return (1);
}
else if (n % d == 0)
{
return (0);
}
else
{
return (is_prime_helper(n, d + 1));
}
}
/**
 * is_prime_number - states if number is prime
 * @n:int
 * Return:int
 */
int is_prime_number(int n)
{
if (n <= 1)
{
return (0);
}
else
{
return (is_prime_helper(n, 2));
}
}
