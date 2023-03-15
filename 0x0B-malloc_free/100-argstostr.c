#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: pointer of an array of char
 */
char *argstostr(int ac, char **av)
{
	int total_length;
	int i, j;
	char *output = NULL;
	int index;

	if (ac == 0 || av == NULL)
		return (NULL);

	total_length = 0;
	for (i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);

		for (j = 0; av[i][j] != '\0'; j++)
			total_length++;
		total_length++;
	}

	output = (char *) malloc(total_length * sizeof(char));
	if (output == NULL)
		return (NULL);

	index = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			output[index] = av[i][j];
			index++;
		}
		output[index] = '\n';
		index++;
	}
	output[index] = '\0';

	return (output);
}

