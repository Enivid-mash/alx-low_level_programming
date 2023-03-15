#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * alloc_grid - returns pointer to a 2 dimensional array of integers.
 *
 * @width: width of the array.
 * @height: height of the array.
 *
 * Return: pointer
 */
int **alloc_grid(int width, int height)
{
	int **gridout;
	int i, j;

	if (width < 1 || height < 1)
	return (NULL);

	/* Allocate memory for height number of pointers to int */
	gridout = (int **)malloc(height * sizeof(int *));
	if (gridout == NULL)
	return (NULL);

	/* Allocate memory for each row of integers */
	for (i = 0; i < height; i++)
	{
		gridout[i] = (int *)malloc(width * sizeof(int));
		if (gridout[i] == NULL)
		{
			for (j = i - 1; j >= 0; j--)
			free(gridout[j]);
			free(gridout);
			return (NULL);
		}
	/* Initialize each element of the row to zero */
		for (j = 0; j < width; j++)
			gridout[i][j] = 0;
	}

	return (gridout);
}
