#include <stdio.h>

/**
 * main - prints exactly and that piece of art is useful"
 *
 * Return: retuns 1
 */
int main(void)
{
	char words[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19";
	int i;

	for (i = 0; i < 58; i++)
		putchar(words[i]);
	putchar(10);
	return (1);
}
