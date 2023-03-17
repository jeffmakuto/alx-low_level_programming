#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16
 * in lowercase
 * Return: Always 0 (success)
 */
int main(void)
{
	int n;
	int m;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + '0');
	}
	for (m = 0; m <= 5; m++)
	{
		putchar(m + 'a');
	}
	putchar('\n');
	return (0);
}
