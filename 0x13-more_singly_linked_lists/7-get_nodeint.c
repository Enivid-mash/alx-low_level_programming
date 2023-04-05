#include "lists.h"

/**
 * get_tempint_at_index - returns the nth temp of a listint_t linked list.
 *
 * @head: head temp pointer
 * @index: index
 *
 * Return: temp
 */
listint_t *get_tempint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *temp;

	for (temp = head, i = 0; temp && i < index; temp = (*temp).next, i++)
		;
	return (temp);
}
