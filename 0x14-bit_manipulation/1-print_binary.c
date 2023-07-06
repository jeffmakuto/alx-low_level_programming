#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 *
 * @n: decimal number to convert to binary
 *
 * Return: Void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;

	if (!n)
	{
		putChar('0');
		return;
	}

	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if ((n & mask))
			putChar('1');
		else
			putChar('0');
		mask >>= 1;
	}
}
