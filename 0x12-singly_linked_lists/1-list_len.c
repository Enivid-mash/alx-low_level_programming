#include "lists.h"
/**
 * list_len - returns then number of elements in a list.
 * @h: pointer to list_t
 * Return: number of elements
 */

size_t list_len(const list_t *h)
{
	size_t n_count;

	n_count = 0;
	while (h != NULL)
	{
		h = (*h).next;
		n_count++;
	}
	return (n_count);
}
