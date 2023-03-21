#include "main.h"
#include <stdio.h>

/**
 * print_times_table - print the @n times table.
 * @n: must be in range 0 to 15
 * * Return: void
 */
void print_times_table(int n)
{
	int i, j, max, width;

	if (n < 0 || n > 15)
	{
		return;
	}

	max = n * n;
	width = 1;

	/*determine maximum width of each column*/
	while (max > 0)
	{
		max /= 10;
		width++;
	}

	for (i = 0; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			int v = i * j;

			if (j == 0)
			{
				printf("%*d", width, v);
			}
			else
			{
				printf(", %*d", width, v);
			}
		}

		printf("\n");
	}
}
