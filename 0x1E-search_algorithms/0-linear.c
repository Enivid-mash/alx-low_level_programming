#include "search_algos.h"

/**
 * linear_search - searches an array using Linear search algorithm
 *
 * @array: array
 * @size: size of the array
 * @value: value to search
 * Return: Index of the value if found, otherwise -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%i]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
