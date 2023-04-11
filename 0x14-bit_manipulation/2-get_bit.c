#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 *
 * @n: bit as argument.
 * @index: index of bit
 *
 * Return: value of bit or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{

	if ((n & (1 << index)) == 0)
		return (0);

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return (1);
}
