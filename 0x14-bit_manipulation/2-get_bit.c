#include "main.h"

/**
 * get_bit - Retrieves the value of a specific bit at a given index
 *
 * @n: The unsigned long integer from which to retrieve the bit
 *
 * @index: The index of the bit to retrieve
 *
 * Return: The value of the bit at the specified index (0 or 1) or
 * -1 in case of an error (index out of range).
 */
int get_bit(unsigned long int n, unsigned int index)
{
    unsigned long int mask = 1UL << index;

    if (index >= (sizeof(unsigned long int) * 8))
        return (-1); /* Error: index out of range */

    return ((n & mask) != 0);
}

