#include "main.h"

int natural_sqrt_recursion(int n, int i);

/**
 * _sqrt_recursion - computes the natural square root of a number
 * @n: squaroot operand
 *
 * Return: the resulting square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (natural_sqrt_recursion(n, 0));
}

/**
 * natural_sqrt_recursion - computes the actual natural square root
 * @n:squaroot operand
 * @i: iterator
 *
 * Return: resulting square root
 */
int natural_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (natural_sqrt_recursion(n, i + 1));
}
