#include "main.h"

/**
 * _abs - computes the absolute value of an integer.
 * @n: the value of the integer
 *
 * Return: 0
 */
int _abs(int n)
{
	if (n > 0 || n == 0)
		return (n);
	else
		return (n * -1);
}
