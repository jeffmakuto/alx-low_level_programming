#include "main.h"

/**
 * binary_to_uint - converts a binary number to an integer
 *
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars
 * in the string b that is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, decimal = 0;

	if (!b)
		return (0);

	/* Iterate through the string from left to right */
	for (i = 0; b[i]; i++)
	{
		if (b[i] == '0' || b[i] == '1')
			decimal = (decimal << 1) + (b[i] - '0');
		else
			return (0);
	}

	return (decimal);
}
