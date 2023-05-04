#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_endianness - Checks the endianness
 * Return: if big_endian - 0
 *         if little-endian - 1
 *
 */
int get_endianness(void)
{
unsigned int x = 1;
char *c = (char *)&x;

return ((int)*c);
}

