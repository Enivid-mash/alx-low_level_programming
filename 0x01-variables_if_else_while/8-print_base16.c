#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase
 *
 * Return: returns 0
 */
int main(void)
{
	int i;
	int j = 97;

	for (i = 48; i <= 57; i++)
		putchar(i);
	while (j <= 102)
	{
		putchar(j);
		j++;
	}
	putchar(10);
	return (0);
}
