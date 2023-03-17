#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This program prints the digits 0-9 to the console
 * using the putchar function.
 *
 * Return: ALways 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + 48);
	}
	putchar('\n');
	return (0);
}
