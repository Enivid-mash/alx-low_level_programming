#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, followed by a new line
 *
 * Return: return 0
 */
int main(void)
{
	int i, j;

	for (i = 97; i <= 122; i++)
		putchar(i);
	for (j = 65; j <= 90; j++)
		putchar(j);
	putchar(10);
	return (0);
}
