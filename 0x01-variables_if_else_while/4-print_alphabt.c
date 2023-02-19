#include <stdio.h>

/**
 * main - prints the alphabet in lowercase except q and e
 *
 * Return: return 0
 */
int main(void)
{
	int i;

	for (i = 97; i <= 122; i++)
	{
		if ((i == 101) || (i == 113))
		{
			i = i + 1;
		}
		putchar(i);
	}
	putchar(10);
	return (0);
}
