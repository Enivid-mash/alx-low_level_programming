#include "search_algos.h"

/**
 * binary_search - searches for value using binary search algorithm
 * @array: pointer to the first element of array to search
 * @size: size of the array
 * @value: value to search
 *
 * Return: index containing value
 */
int binary_search(int *array, size_t size, int value)
{
	int left, mid, right, x;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		printf("Searching in array: ");
		for (x = left; x <= right; x++)
		{
			printf("%i", array[x]);
			if (x < right)
				printf(", ");
		}
		printf("\n");

		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}

	return (-1);
}
