#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints sum of the two diagonals of
 * a square matrix of integers
 *
 * @a: pointer to the matrix
 *
 * size: size of the matrix
 *
 * Return: Void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += *(a + i * size + i);
		sum2 += *(a + i * size + size - i - 1);
	}

	printf("%d, %d\n", sum1, sum2);
}
