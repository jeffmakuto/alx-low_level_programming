#include "main.h"

/**
 * print_numbers - prints the numbers, form 0 to 9,
 * followed by a new line
 *
 * Description: its a function
 *
 * Return: Void
 */
void print_numbers(void)
{
	char i;

	for (i = 0; i <= 9; i++)
	{
		_putchar(i + '0');
	}

	_putchar('\n');
}
