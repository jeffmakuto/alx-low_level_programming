#include <stdio.h>
/**
 * print_array - prints @n elements of @a
 * @a: reference to an array of integers
 * @n: the number of elements to be printed
 *
 * Retun: Void
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		if (i < n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
