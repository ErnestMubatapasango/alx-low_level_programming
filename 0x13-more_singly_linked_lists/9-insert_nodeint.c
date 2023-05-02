#include <stdlib.h>
#include "lists.h"
#include <string.h>
#include <stdio.h>
/**
 * insert_nodeint_at_index - inserts a new node to a listint_t,
 * list at a given position
 * @head: A pointer to the address of the head of the listint_t list
 * @idx: The index of the listint_t list where the new node should,
 * be added - indeces start at 0
 * @n: The integer for the new node to contain
 * Return: If the function fails - NULL.
 * Otherwise - the address of the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *current = *head;
listint_t *prev = NULL;
unsigned int count = 0;
while (current != NULL && count < idx)
{
prev = current;
current = current->next;
count++;
}
if (count != idx)
{
return (NULL);
}
listint_t *new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = n;
new_node->next = current;
if (prev == NULL)
{
*head = new_node;
}
else
{
prev->next = new_node;
}
return (new_node);
}

