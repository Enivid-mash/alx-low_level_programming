#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a listint_t list.
 *
 * @head: pointer to head node pointer
 */
void free_listint2(listint_t **head)
{
	listint_t *c_node;
	listint_t *temp;

	if (!head)
		return;
	c_node = *head;
	while (c_node)
	{
		temp = c_node;
		c_node = temp->next;
		free(temp);
	}
	*head = NULL;
}
