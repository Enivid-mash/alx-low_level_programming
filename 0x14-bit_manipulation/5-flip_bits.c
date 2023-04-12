#include "main.h"

/**
 * flip_bits - finds flip bits needed for one number to other
 *
 * @n: number
 * @m: other number
 *
 * Return: the number of bits needed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bits = 0;
	unsigned int x_or = n ^ m;

	while (x_or > 0)
	{
		bits += (x_or & 1);
		x_or >>= 1;
	}

	return (bits);
}
