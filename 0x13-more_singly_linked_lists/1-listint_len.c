#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 *
 * @h: head node pointer
 *
 * Return: number of elements in list
 */
size_t listint_len(const listint_t *h)
{
	size_t counter = 0;

	while (h)
	{
		h = (*h).next;
		counter++;
	}
	return (counter);
}
