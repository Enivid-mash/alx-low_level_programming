#include "main.h"

/**
 * swap_int - swaps the values of two integers
 *
 * @i: pointer one
 * @j: pointer two
 */
void swap_int(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
