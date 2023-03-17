#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: this program prints all possible combinations of two digits,
 * separated by "," and in ascending order, where 01 and 10 are considered
 * the same combination
 * of two digits 0 and 1
 *
 * Return: Always 0(Sucess)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			putchar(i + '0');
			putchar(j + '0');

			if (i < 8)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
