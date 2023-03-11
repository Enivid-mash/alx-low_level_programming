#include <stdio.h>
#include "main.h"

/**
 * main - prints its name, followed by a new line.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: zero on success
 */
int main(int argc, char *__attribute__((unused)) argv[])
{
	printf("%s\n", *argv);

	return (0);
}
