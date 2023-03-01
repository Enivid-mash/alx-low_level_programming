#include "main.h"

/**
 * *_strcat - concatenates two strings
 *
 * *@dest: first parameter pointer
 * *@src: second parameter pointer
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	len = 0;
	while (dest[len] != '\0')
		len++;

	for (i = 0; src[i] != '\0'; i++, len++)
		dest[len] = src[i];

	dest[len] = '\0';

	return (dest);
}
