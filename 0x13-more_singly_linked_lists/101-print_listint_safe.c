#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow, *fast;
size_t count = 0;

if (head == NULL)
return (0);

slow = head;
fast = head->next;

while (fast != NULL && fast != slow)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next;
if (fast != NULL)
fast = fast->next;
}

if (fast == NULL)
{
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}
else
{
printf("[%p] %d\n", (void *)slow, slow->n);
printf("-> [%p] %d\n", (void *)fast, fast->n);
count += 2;
slow = slow->next;
while (slow != fast)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
count++;
}
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}
return (count);
}

