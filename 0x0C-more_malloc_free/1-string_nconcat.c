#include "main.h"
#include <stdlib.h>

int _strlen(char *s);
/**
 * string_nconcat - concatenates two strings
 * @s1: string one.
 * @s2: string two.
 * @n: number of bytes for s2
 *
 * Return: pointer to new memory.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s, *r;
	unsigned int lens1, lens2;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	lens1 = _strlen(s1);
	lens2 = _strlen(s2);

	lens2 = lens2 > n ? n : lens2;
	r = s = malloc(lens1 + lens2 + 1);
	if (!s)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	while (lens2--)
		*s++ = *s2++;
	*s = '\0';
	return (r);
}

/**
 * _strlen - determines the length of a string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
