#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node
 *
 * @h: head node pointer
 * @idx: index of new node
 * @n: value of new node
 * Return: address of new node, or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *current = *h;

	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (*h == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*h = new_node;
		return (new_node);
	}
	if (idx == 0)
	{
		new_node->next = *h;
		new_node->prev = NULL;
		(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current->next;
	new_node->prev = current;
	if (current->next != NULL)
		current->next->prev = new_node;
	current->next = new_node;
	return (new_node);
}
