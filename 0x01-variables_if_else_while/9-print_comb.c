#include <stdio.h>

/**
 * main -  prints all possible combinations of single-digit numbers
 *
 * Return: returns 0
 */
int main(void)
{
	int i = 48;

	while (i <= 57)
	{
		putchar(i);
		if (i == 57)
			break;
		putchar(44);
		putchar(32);
		i++;
	}
	putchar(10);
	return (0);
}
