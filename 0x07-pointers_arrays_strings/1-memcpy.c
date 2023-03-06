#include "main.h"

/**
 * *_memcpy - a function that copies memory area
 *
 *@dest: destination memory area
 *@src: source memory
 *@n: number of bytes to copy
 * Return: a pointer to the memory area dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *udest = (char *)dest;
	const char *usrc = (const char *)src;

	for (; n > 0; ++udest, ++usrc, --n)
		*udest = *usrc;
	return (dest);
}
