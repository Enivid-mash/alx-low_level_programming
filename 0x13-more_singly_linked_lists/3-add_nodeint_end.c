#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 *
 * @head: pointer to head node pointer
 * @n: new node value
 *
 * Return: address of the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node;
	listint_t *n_node = malloc(sizeof(listint_t));

	if (!head || !n_node)
		return (NULL);
	(*n_node).n = n;
	(*n_node).next = NULL;
	if (!*head)
		*head = n_node;
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = n_node;
	}
	return (n_node);
}
