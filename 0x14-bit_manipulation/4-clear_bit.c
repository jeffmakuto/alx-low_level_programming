/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 *
 * @n: Pointer to the unsigned long integer in which to clear the bit
 *
 * @index: The index of the bit to clear
 *
 * Return: 1 if the bit was successfully cleared, or -1 if an error
 * occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /* Error: index out of range */

	*n &= ~(1UL << index);
	return (1);
}

