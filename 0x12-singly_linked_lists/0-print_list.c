#include "lists.h"
/**
 * print_list - prints all the elements of a list_t list.
 * @h: a pointer to list_t
 * Return: the count of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		count++;
		h = h->next;
	}
	return (count);
}
