#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - cause normal process termination with a status value of 98
 *
 * @b: allocated memory
 *
 * Return: a pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
void *a = malloc(b);
if (!a)
{
exit(98);
}

return (a);
}

