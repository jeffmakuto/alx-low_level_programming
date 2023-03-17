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

	for (n = 48; n <= 97; n++)
	{
		putchar(n);
	}
	for (m = 97; m <= 102; m++)
	{
		putchar(m);
	}
	putchar('\n');
	return (0);
}
