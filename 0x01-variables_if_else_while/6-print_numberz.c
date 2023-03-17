#include <stdio.h>

/**
 * main - Entry point
 * Description: prints all digit 0-9 to the console
 *
 * return: always 0 (Sucess)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + 48);
	}
	putchar('\n');
	return (0);
}
