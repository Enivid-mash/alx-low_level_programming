#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node
 *
 * @head: head node pointer
 * @index: index of nth node
 * Return: nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i = 0;

	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	return (current);
}
