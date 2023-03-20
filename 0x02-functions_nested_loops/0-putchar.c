#include "main.h"

/**
 * main - Entry level
 *
 * Description: prints _putchar, followed by a new line
 *
 * Return: ALways 0 (success)
 */
int main(void)
{
	int i;
	char *msg = "_putchar";

	for (i = 0; i < 8; i++)
	{
		_putchar(msg[i]);
	}
	_putchar('\n');
	return (0);
}
