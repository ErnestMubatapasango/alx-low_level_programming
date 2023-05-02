#include <stdlib.h>
#include "lists.h"
#include <stdio.h>
#include <string.h>
/**
 * delete_nodeint_at_index - Deletes the node ata a given index,
 * of a listint_t list
 * @head: A pointer to the address of the head of the listint_t list
 * @index:
 * The index of the node to be deleted - indeces start at 0
 * Return: On success - 1,
 * On failure - -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current = *head;
listint_t *prev = NULL;
unsigned int count = 0;
while (current != NULL && count < index)
{
prev = current;
current = current->next;
count++;
}
if (current == NULL)
{
return (-1);
}
if (prev == NULL)
{
*head = current->next;
}
else
{
prev->next = current->next;
}
free(current);
return (1);
}

