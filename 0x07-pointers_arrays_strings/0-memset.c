#include "main.h"

/**
 * *_memset - a function that fills memory with a constant byte.
 *
 * @s: memory area
 * @b: constant byte
 * @n: n bytes of  memory arear
 *
 * Return: a pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	if (n != 0)
	{
		unsigned char *su = (unsigned char *)s;

		do {
			*su++ = (unsigned char)b;
		} while (--n != 0);
	}
	return (s);
}
