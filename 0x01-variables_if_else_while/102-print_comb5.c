#include <stdio.h>

/**
 * main -  prints all possible combinations of two two-digit numbers
 *
 * Return: returns 0
 */
int main(void)
{
	int i;
	int j;

	for (i = 0; i <= 98; i++)
	{
		for (j = i + 1; j <= 99; j++)
		{
			putchar((i / 10) + 48);
			putchar((i % 10) + 48);
			putchar(32);
			putchar((j / 10) + 48);
			putchar((j % 10) + 48);
			if (i == 98 && j == 99)
				break;
			putchar(44);
			putchar(32);
		}
	}
	putchar(10);
	return (0);
}
