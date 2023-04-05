#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t linked list
 *
 * @head: pointer to head node pointer
 *
 * Return: head node's data
 */
int pop_listint(listint_t **head)
{
	int i;
	listint_t *node;

	if (!(*head) || !head)
		return (0);
	node = *head;
	i = (*node).n;
	*head = (*(*head)).next;
	free(node);
	return (i);
}
