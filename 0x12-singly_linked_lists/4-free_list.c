#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: head of list.
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *c_node;

	while ((c_node = head) != NULL)
	{
		head = (*head).next;
		free((*c_node).str);
		free(c_node);
	}
}
