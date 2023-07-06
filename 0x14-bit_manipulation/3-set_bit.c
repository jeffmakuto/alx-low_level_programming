#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 *
 * @n: Pointer to the unsigned long integer in which to set the bit
 *
 * @index: The index of the bit to set
 *
 * Return: 1 if the bit was successfully set, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /* Error: index out of range */

	*n |= (1UL << index);
	return (1);
}

