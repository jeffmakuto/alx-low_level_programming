#include <stdio.h>
#include "main.h"

/**
 * print_chessboard - prints the chessboard
 *
 * Description: This function prints an 8x8 chessboard,
 * represented as a two-dimensional array of characters.
 *
 * @a: the chessboard to print
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	printf("a: %lu\n", sizeof(a));

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
