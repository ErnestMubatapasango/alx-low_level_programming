#include <stdlib.h>
#include "lists.h"
/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 * Return: the data inside the element that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
if (*head == NULL)
{
return (0);
}
int data = (*head)->n;
listint_t *next_node = (*head)->next;
free(*head);
*head = next_node;
return (data);
}

