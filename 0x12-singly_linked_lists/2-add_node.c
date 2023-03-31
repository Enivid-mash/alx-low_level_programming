#include "lists.h"
/**
 * add_node -  adds a new node at beginning of a list_t
 * @head: double pointer to list_t
 * @str: pointer of type char
 * Return: address of the new element.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *n_node;
	size_t n;

	n_node = malloc(sizeof(list_t));
	if (n_node == NULL)
		return (NULL);

	n_node->str = strdup(str);

	for (n = 0; str[n]; n++)
		;
	n_node->len = n;
	n_node->next = *head;
	*head = n_node;
	return (*head);
}
