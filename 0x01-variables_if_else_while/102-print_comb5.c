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
	int k;
	int m;

	for (i = 48; i <= 57; i++)
	{
		for (j = 48; j <= 57; j++)
		{
			for (k = 48; k <= 57; k++)
			{
				for (m = 48; m <= 57; m++)
				{
				if (((i != j) && (j != k) && (k != m)) && ((i <= k) && (i <= j)))
				{
					putchar(i);
					putchar(j);
					putchar(32);
					putchar(k);
					putchar(m);
					putchar(44);
					putchar(32);
				}
				}
			}
		}
	}
	putchar(10);
	return (0);
}
