#include "lists.h"

/**
 * sum_dlistint - returns sum of data in nodes
 *
 * @head: head node pionter
 * Return: sum of data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
