#include "main.h"

/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: the function parameter
 *
 * Return: return 1 if successful otherwise 0
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
