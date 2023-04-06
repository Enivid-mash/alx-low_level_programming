#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - adds a n_node node
 * @head: head node pointer
 * @idx: index of the list
 * @n: n_node node to be added
 * Return: pointer to the n_node node,
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int node;
	listint_t *n_node, *tmp = *head;

	n_node = malloc(sizeof(listint_t));

	if (n_node == NULL)
		return (NULL);
	(*n_node).n = n;
	if (idx == 0)
	{
		(*n_node).next = tmp;
		*head = n_node;
		return (n_node);
	}
	for (node = 0; node < (idx - 1); node++)
	{
		if (tmp == NULL || (*tmp).next == NULL)
		return (NULL);
		tmp = (*tmp).next;
	}
	(*n_node).next = (*tmp).next;
	(*tmp).next = n_node;
	return (n_node);
}
