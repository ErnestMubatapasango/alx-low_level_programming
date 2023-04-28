#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node - Adds a new node at the beginning of a list_t list.
* @head: A pointer to the head of the list.
* @str: The string to add to the new node.
*
* Return: A pointer to the new node, or NULL on failure.
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;

/* Allocate memory for the new node */
new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

/* Set the new node's string and length */
new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}
new_node->len = strlen(str);

/* Set the new node's next pointer */
new_node->next = *head;

/* Set the head of the list to the new node */
*head = new_node;

return (new_node);
}



