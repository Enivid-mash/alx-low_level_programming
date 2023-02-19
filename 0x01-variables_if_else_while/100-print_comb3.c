#include <stdio.h>

/**
 * main -  prints all possible different combinations of two digits
 *
 * Return: returns 0
 */
int main(void)
{
	int i;
	int j;

	for (i = 48; i <= 57; i++)
	{
		for (j = 48; j <= 57; j++)
		{
			if ((i != j) && (i < j))
			{
				putchar(i);
				putchar(j);
				putchar(44);
				putchar(32);
			}
		}
	}
	putchar(10);
	return (0);
}
