#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string
 *
 * Return: a pointer
 */
char *_strdup(char *str)
{
	unsigned int i = 0;
	unsigned int j = 0;
	char *pstr = NULL;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	pstr = (char *)malloc((i + 1) * sizeof(char));

	if (pstr == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		pstr[j] = str[j];

	return (pstr);
}
