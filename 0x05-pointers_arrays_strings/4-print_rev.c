#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a newline
 * @s: the reference to the string
 */
void print_rev(char *s)
{
	int i = 0;
	char c = *s;

	/* get string length */

	while (c != '\0')
	{
		c = *(s + ++i);
	}

	/* print string in reverse */
	c = (*s + i--);
	while (i >= 0)
	{
		_putchar(*(s + i--));
	}
	_putchar('\n');
}
