#include "main.h"

/**
 * print_line - prints draws a straight line in the terminal.
 *
 * @n: parameter
 * Return: void
 */
void print_line(int n)
{
	int i;

	if (n <= 0)
		_putchar(10);
	else
	{
		for (i = 1; i <= n; i++)
			_putchar(95);
		_putchar(10);
	}
}
