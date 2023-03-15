#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: a pointer
 */
char *str_concat(char *s1, char *s2)
{
	char *pss;
	unsigned int i, j, k, m;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;

	for (j = 0; s2[j] != '\0'; j++)
		;

	pss = malloc(sizeof(char) * (i + j + 1));

	if (pss == NULL)
	{
		free(pss);
		return (NULL);
	}

	for (k = 0; k < i; k++)
		pss[k] = s1[k];

	m = j;
	for (j = 0; j <= m; k++, j++)
		pss[k] = s2[j];

	return (pss);
}
