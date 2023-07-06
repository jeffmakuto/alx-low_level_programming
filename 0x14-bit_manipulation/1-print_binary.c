#include "main.h"

/**
 * print_binary - print number in base 2
 *
 * @n: the number to print
 *
 * Return: Void
 */
void print_binary(unsigned long int n)
{
	unsigned int bits;
	char first = 1;

	for (bits = sizeof(n) * 8; bits > 0; bits--)
	{
		char bit = (n >> (bits - 1)) & 0x01;

		if (bit || (!bit && !first) || !n)
		{
			first = 0;
			_putchar(bit + '0');
		}
		if (!n)
			break;
	}
}
