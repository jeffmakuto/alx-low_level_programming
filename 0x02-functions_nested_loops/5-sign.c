#include "main.h"

#include "main.h"

/**
 * print_sign - check @i sign and prints it
 * @i: the number to check
 *
 * Return: 1 if @i is positive
 * or 0 if @i is zero
 * or -1 if @i is negative
 */
int print_sign(int i)
{
	int j = (i > 0) ? 1 : (i < 0) ? -1 : 0;

	if (j == 1)
	{
		_putchar('+');
	}
	else if (j == -1)
	{
		_putchar('-');
	}
	else
	{
		_putchar('0');
	}
	return (j);
}
