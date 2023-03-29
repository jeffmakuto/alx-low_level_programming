#include "main.h"

/**
 * print_number - print number in ascii characters
 * @n: the number to print
 * Return: void
 */
void print_number(int n)
{
	unsigned int a, tens = 1;

	if (n < 0)
	{
		_putchar(45);
		a = -n;
	}
	else
	{
		a = n;
	}

	/* find the nearest floored 10s to a*/
	while (a / tens >= 10)
		tens *= 10;

	while (a > 0 || tens > 0)
	{
		_putchar(a / tens + 48);
		a %= tens;
		tens /= 10;
	}
}

