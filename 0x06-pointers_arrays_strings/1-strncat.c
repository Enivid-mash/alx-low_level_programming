#include "main.h"

/**
 * *_strncat - concatenates two strings
 *
 * *@dest: first parameter pointer
 * *@src: second parameter pointer
 * @n: third function parameter
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, len;

	len = 0;
	while (dest[len] != '\0')
		len++;

	for (i = 0; i < n && src[i] != '\0'; i++, len++)
		dest[len] = src[i];

	dest[len] = '\0';

	return (dest);
}
