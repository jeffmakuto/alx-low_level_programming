#include "main.h"

/**
 * puts_half - prints the 2nd half of the string to stdout
 * @str: the reference to the string
 */
void puts_half(char *str)
{
	int i, n, len = 0;
	char c = *str;

	while (c != '\0')
	{
		c = *(str + ++len);
	}
	n = len / 2 + (len % 2 == 0 ? 0 : 1);

	for (i = n; i < len; i++)
	{
		_putchar(*(str + i));
	}
	_putchar('\n');
}
