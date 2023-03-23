#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
* sum_them_all - returns the sum of all its parameters.
* @n: first fixed parameter
* Return: sum
*/

int sum_them_all(const unsigned int n, ...)
{
	unsigned int  count;
	int sum = 0;
	va_list parg;

	if (n == 0)
		return (0);

	va_start(parg, n);
	for (count = 0; count < n; count++)
	{
		sum += va_arg(parg, int);
	}
	va_end(parg);
	return (sum);
}
