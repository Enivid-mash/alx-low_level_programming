#include "lists.h"

/**
 * get_nodeint_at_index - gives nth node of a listint_t linked list
 * @head: head
 * @index: index of the node
 *
 * Return: address of nth node
 **/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current_node;

	register uint count = 0;

	current_node = head;
	while (current_node)
	{
		if (count == index)
			return (current_node);
		count++;
		current_node = (*current_node).next;
	}
	return (current_node);
}
