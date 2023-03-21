#include "main.h"

/**
 * print_alphabet: Entry point
 *
 * Description: This function prints the alphabet in lowercase to the console,
 * starting with 'a' and ending with 'z' followed by a new line
 *
 * Return: Always 0 (success)
 */
void print_alphabet(void)
{
	char i = 'a';

	while (i <= 'z')
	{
		_putchar(i);
		i++;
	}
	_putchar('\n');
}
