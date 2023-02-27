#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 *
 * @str: pointer as parameter
 */
void puts_half(char *str)
{
	int i, num, len;

	len = 0;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
	{
		for (i = len / 2; str[i] != '\0'; i++)
			_putchar(str[i]);
	} else if (len % 2)
	{
		for (num = (len - 1) / 2; num < len - 1; num++)
			_putchar(str[num + 1]);
	}
	_putchar('\n');
}
