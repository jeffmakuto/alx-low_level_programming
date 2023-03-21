#include "main.h"

/**
 * print_int - print 2 digits number as ascii string
 * @i: the number to print
 * Return: void
 */
void print_int(int i)
{
	int a;
	int b;

	a = i / 10;
	b = i % 10;

	_putchar(a + 48);
	_putchar(b + 48);
}

/**
 * jack_bauer - print every minute of the day
 *
 * Return: void
 */
void jack_bauer(void)
{
	int j;

	for (j = 0; j < 1440; j++)
	{
		int k;
		int l;

		k = j / 60;
		l = j % 60;

		print_int(k);
		_putchar(':');
		print_int(l);
		_putchar('\n');
	}
}
