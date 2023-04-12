#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 *
 * @n: bit
 * @index: index to set
 *
 * Return: 1 on success, otherwise -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i = 0x01;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	i = ~(i << index);
	if (i == 0x00)
		return (-1);

	*n &= i;

	return (1);
}
