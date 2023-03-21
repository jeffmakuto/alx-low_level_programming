#include <stdio.h>

/**
 * main - print the first 50 fibonacci number
 * Return: void
 */
int main(void)
{
	unsigned long i, a = 0, b = 1, f;

	for (i = 0; i < 50; i++)
	{
		f = a + b;
		a = b, b = f;
		if (i < 49)
			printf("%lu, ", f);
		else
			printf("%lu\n", f);
	}

	return (0);
}

