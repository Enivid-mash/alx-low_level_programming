#include "variadic_functions.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_strings - prints strings with separator
 *
 * @separator: the separator
 * @n: arguments
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	int i = n;
	char *str;
	va_list parg;

	if (!n)
	{
		printf("\n");
		return;
	}
	va_start(parg, n);
	while (i--)
		printf("%s%s", (str = va_arg(parg, char *)) ? str : "(nil)",
				i ? (separator ? separator : "") : "\n");
	va_end(parg);
}
