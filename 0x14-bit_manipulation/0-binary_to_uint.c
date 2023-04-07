#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 *
 * @b: pointer to function parameter
 *
 * Return: Zero or decimal equivalent
 **/
unsigned int binary_to_uint(const char *b)
{
	unsigned int count = 0;
	unsigned int sum = 0;
	unsigned int b2 = 0;
	const char *b1 = b;

	if (*b1 == NULL)
		return (0);

	/* the number of binary digits in the input string */
	while (*b1 != '\0')
	{
		if ((*b1 != '1') && (*b1 != '0'))
		return (0);
		count++;
		b1++;
	}

	/* Reset b1 to the beginning of the string */
	b1 = b;

	/* iterates through, converting each binary digit to decimal equivalent */
	while (*b1 != '\0')
	{
		b2 = *b1 - '0';
		sum = sum * 2 + b2;
		--count;
		b1++;
	}

	return (sum);
}
