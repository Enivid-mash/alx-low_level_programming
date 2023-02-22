#include "main.h"

/**
 * jack_bauer - prints every minute of the day of Jack Bauer.
 *
 */
void jack_bauer(void)
{
	int i;
	int j;

	i = 0;

	while (i < 24)
	{
		j = 0;
		while (j < 60)
		{
			_putchar((i / 10) + 48);
			_putchar((i % 10) + 48);
			_putchar(58);
			_putchar((j / 10) + 48);
			_putchar((j % 10) + 48);
			_putchar(10);
			j++;
		}
	i++;
	}
}
