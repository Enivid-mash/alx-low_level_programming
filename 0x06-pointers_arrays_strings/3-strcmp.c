#include "main.h"
/**
 *_strcmp - compares two strings
 *
 *@s1: pointer to first string
 *@s2: pointer to second string
 *
 *Return:  returns an  integer  less  than, equal
 * to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or
 * be greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;

	j = s1[i] - s2[i];
	return (j);
}
