#include <stdio.h>
#include "main.h"

/**
 * print_times_table - print the @n times table.
 * @n: must be in range 0 to 15
 * Return: void
 */
void print_times_table(int n)
{
	int i, j;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int v = i * j;

			if (j == 0)
				printf("0");
			else
				printf("%4d", v);

			if (j < n)
				printf(",");
		}
		printf("\n");
	}

}
