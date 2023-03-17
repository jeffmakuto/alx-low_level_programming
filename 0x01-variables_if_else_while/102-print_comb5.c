#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all possible combinations of two-digit numbers,
 * separated by "," in ascending order, and the numbers should range
 * from 0 to 99
 *All numbers should be printed with two digits, 1 should be printed as 01.
 *00, 01 and 01, 00 are considered as the same combination of numbers 0 and 1
 *Return: Always 0 (success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 99; i++)
	{
		for (j = i + 1; j < 100; j++)
		{
			putchar((i / 10) + '0');
			putchar((i % 10) + '0');
			putchar(' ');
			putchar((j / 10) + '0');
			putchar((j % 10) + '0');

			if (i == 98 && j == 99)
			{
				putchar('\n');
				break;
			}
			putchar(',');
			putchar(' ');
		}
	}
	return (0);
}
