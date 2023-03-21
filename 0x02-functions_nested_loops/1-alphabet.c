#include "main.h"

/**
 * print_alphabet: Entry point
 *
 * Description: prints the alphabet in lowercase, followed by a new line
 *
 * Return: Always 0 (success)
 */
void print_alphabet(void)
{
	char i;

	while (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
