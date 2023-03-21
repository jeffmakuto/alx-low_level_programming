#include "main.h"

/**
 * times_table - prints the 9 table, starting with 0
 *
 */
void times_table(void)
{
	int i;
	int mult;
	int result;

	for (i = 0; i <= 9; i++)
	{
		_putchar('0');

		for (mult = 1; mult <= 9; mult++)
		{
			_putchar(',');
			_putchar(' ');

			result = i * mult;

			_putchar(result <= 9 ? ' ' : (result / 10) + '0');
			_putchar((result % 10) + '0');

		}
		_putchar('\n');
	}
}
