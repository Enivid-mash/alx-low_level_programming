#include "main.h"

/**
 * _strpbrk - searches a string for any of a set fo bytes
 *
 * @s: intial string
 * @accept: where search is done
 *
 * Return: a pointer to the byte in s
 */
char *_strpbrk(char *s, char *accept)
{
	const char *scp, *accept2;

	for (scp = s; *scp != '\0'; ++scp)
	{
		for (accept2 = accept; *accept2 != '\0'; ++accept2)
		{
			if (*scp == *accept2)
				return ((char *)scp);
		}
	}
	return ((void *)0);
}
