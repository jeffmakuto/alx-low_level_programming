#include <stdio.h>

/**
 * main -Entry point
 *
 * Description:prints all possible combinations of three digits,
 * separated by ",", and in ascending order. The three digits
 * must be different, and only the smallest combination of
 * three digits is printed
 *
 * Return: ALways 0 (sucess)
 */
int main(void)
{
	int i, j, k;

	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			for (k = j + 1; k < 10; k++)
			{
				putchar(i + '0');
				putchar(j + '0');
				putchar(k + '0');

				if (i < 7)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
