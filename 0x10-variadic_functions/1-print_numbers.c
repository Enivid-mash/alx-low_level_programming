#include "variadic_functions.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers.
 *
 * @separator: separator
 * @n: second fixed parameter
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list parg;
	int i = n;

	if (separator == NULL)
		separator = "";

	va_start(parg, n);
	if (i--)
		printf("%d", va_arg(parg, int));
	while (i-- > 0)
		printf("%s%d", separator, va_arg(parg, int));
	printf("\n");
	va_end(parg);
}
