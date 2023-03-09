#include "main.h"

int prime_calc(int n, int i);

/**
 * is_prime_number - returns 1 for prime integer  else 0
 * @n: the parameter
 *
 * Return: 1 or 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_calc(n, n - 1));
}

/**
 * prime_calc - computes if a number is prime recursively
 * @n: number to evaluate
 * @i: iterator
 *
 * Return: 1 if n is prime, 0 if not
 */
int prime_calc(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (prime_calc(n, i - 1));
}
