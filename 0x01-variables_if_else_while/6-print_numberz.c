#include <stdio.h>

/**
 * main - prints all single digit numbers starting from 0
 *
 * return: always 0
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + 48);
	}
	putchar("\n");
	return (0);
}
