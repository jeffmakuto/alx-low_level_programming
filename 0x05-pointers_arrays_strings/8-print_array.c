#include <stdio.h>
/**
 * print_array - prints @n elements of an array of integers; @a,
 * followed by a new line
 * @a: reference to an array of integers
 * @b: the number of elements to be printed
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
