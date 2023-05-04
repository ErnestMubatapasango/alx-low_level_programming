#include <stdio.h>
#include "main.h"

/**
 * flip_bits - counts the number of bits to change to gret,
 * from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int x = n ^ m;
unsigned int count = 0;
while (x != 0)
{
count += x & 1;
x >>= 1;
}
return (count);
}

