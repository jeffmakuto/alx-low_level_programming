#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 *
 * @s: string to be printed of type char
 *
 * Return: Void
 */
void _puts_recursion(char *s)
{
	int i;

	for (i = 0; *s != '\0'; i++)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}
