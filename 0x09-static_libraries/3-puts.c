#include "main.h"

/**
 * * _puts - prints a string, followed by a newline to stdout
 * @str: the reference to the string
 * Return: Void
 */
void _puts(char *str)
{
	int i = 0;
	char c = *str;

	while (1)
	{
		c = *(str + i++);

		if (c == '\0')
		{
			break;
		}
		_putchar(c);
	}
	_putchar('\n');
}
