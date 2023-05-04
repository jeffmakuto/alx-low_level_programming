/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another.
 *
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	while (diff != 0)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}
