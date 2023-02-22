#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase
 *
 * Return: return 0
 */
void print_alphabet_x10(void)
{
	int i;
	int count;

	for (count = 0; count < 10; count++)
	{
		for (i = 97; i <= 122; i++)
			_putchar(i);
		_putchar(10);
	}
}
