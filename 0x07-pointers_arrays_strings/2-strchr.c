#include "main.h"

/**
 * _strchr - a function that locates a character in a string
 *
 * @s: the string to search
 * @c: the character to find
 *
 * Return: a pointer to the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
	const char ch = c;

	for (; *s != ch; ++s)
	{
		if (*s == '\0')
			return ((void *)0);
	}
	return ((char *)s);
}
