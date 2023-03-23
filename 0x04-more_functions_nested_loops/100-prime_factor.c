#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Description: prints the largest prime factor of the number 612852475143,
 * followed by a new line
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	unsigned long n = 612852475143, i, m = 0;

	while (n % 2 == 0)
	{
		n /= 2;
	}

	for (i = 3; i < sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			if (i > m)
			{
				m = i;

				n /= i;
			}
		}
	}

	if (n > 2 && n > m)
	{
		m = n;
	}

	printf("%lu\n", n);

	return (0);
}
