#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 *
 * @s: the initial memory area
 * @accept: the secondary memory area
 *
 * Return: bytes in s of only from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	const char *s1, *accept1;

	for (s1 = s; *s1 != '\0'; ++s1)
	{
		for (accept1 = accept; ; ++accept1)
		{
			if (*accept1 == '\0')
				return (s1 - s);
			else if (*s1 == *accept1)
				break;
		}
	}
	return (s1 - s);
}
