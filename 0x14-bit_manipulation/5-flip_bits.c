#include "main.h"

/**
 * flip_bits - Calculates the number of bits needed to flip to
 * transform one number to another.
 *
 * @n: The first unsigned long integer.
 *
 * @m: The second unsigned long integer.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result)
	{
		if ((xor_result & 1) == 1)
			count++;
		xor_result >>= 1;
	}

	return (count);
}

