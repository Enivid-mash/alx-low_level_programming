#include "main.h"
/**
 *leet - encodes a string into 1337
 *
 *@s: pointer to string
 *
 *Return: pointer to s.
 */
char *leet(char *s)
{
	int i, j;
	char l_l[] = "aAeEoOtTlL";
	char l_n[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (j < 10)
		{
			if (l_l[j] == s[i])
				s[i] = l_n[j];
			j++;
		}
		i++;
	}
	return (s);
}
