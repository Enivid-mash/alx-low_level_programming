#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index
 *
 * @head: head node pointer
 * @index: index of new node
 * Return: 1 on success, -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current = *head;

	if (*head == NULL)
		return (-1);

	for (i = 0; i < index; i++)
	{
		if (current == NULL)
			return (-1);

		current = current->next;
	}

	if (current == *head)
		*head = current->next;

	if (current->prev != NULL)
		current->prev->next = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
