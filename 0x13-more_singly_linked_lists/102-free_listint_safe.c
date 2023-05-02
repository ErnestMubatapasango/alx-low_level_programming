#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
size_t count = 0;
listint_t *current;

while (*h != NULL)
{
current = *h;
*h = (*h)->next;
free(current);
count++;
if (current <= (*h))
{
*h = NULL;
break;
}
}

return (count);
}

