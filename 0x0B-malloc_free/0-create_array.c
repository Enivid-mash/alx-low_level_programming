#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initialzes it.
 * @size: array size
 * @c: initializing char
 *
 * Return: a pointer or NULL
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *pc = NULL;

	if (size == 0)
		return (NULL);

	pc = (char *)malloc(size * sizeof(c));

	if (pc == NULL)
		return (NULL);
	while (*pc)
	{
		pc[i] = c;
		c++;
	}
	return (pc);
}
