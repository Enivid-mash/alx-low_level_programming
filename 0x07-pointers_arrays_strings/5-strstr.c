#include "main.h"

/**
 * _strstr - locates a substring
 *
 * @haystack: the string
 * @needle: the substring
 *
 * Return:  pointer to beginning of located substring, or (void *)0
 */
char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
		return ((char *)haystack);
	for (; (haystack = _strchr(haystack, *needle)) != (void *)0; ++haystack)
		{
		const char *sc1, *sc2;

		for (sc1 = haystack, sc2 = needle; ; )
		{
			if (*++sc2 == '\0')
				return ((char *)haystack);
			else if (*++sc1 != *sc2)
				break;
		}
		}
	return ((void *)0);
}

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

