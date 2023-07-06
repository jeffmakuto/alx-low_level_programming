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
	int flag;

	if (n == 0)
	{
		putChar('0');
		return;
	}

	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	flag = 0;

	while (mask > 0)
	{
		if ((n & mask))
		{
			putChar('1');
			flag = 1;
		}
		else if (flag == 1)
			putChar('0');
		mask >>= 1;
	}
}
