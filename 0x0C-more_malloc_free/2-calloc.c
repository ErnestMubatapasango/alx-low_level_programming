#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array of @nmemb elements of
 * @size bytes each and returns a pointer to the allocated memory.
 *
 * @nmemb: allocate memory for array
 * @size: allocate element of size bytes
 *
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
unsigned int i;
char *cptr;

if (nmemb == 0 || size == 0)
{
return (NULL);
}

ptr = malloc(nmemb * size);
if (ptr == NULL)
{
return (NULL);
}

cptr = ptr;
for (i = 0; i < nmemb * size; i++)
{
cptr[i] = 0;
}

return (ptr);
}

