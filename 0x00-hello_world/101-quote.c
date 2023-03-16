#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 * Return: Always 1 (Error)
 */
int main(void)
{
	const char *str1 = "and that piece of art is useful\"";
	const char *str2 = " - Dora Korpar, ";
	const char *str3 = "2015-10-19\n";

	/* write to stdout using the write function */

	write(STDOUT_FILENO, str1, 32);
	write(STDOUT_FILENO, str2, 16);
	write(STDOUT_FILENO, str3, 12);

	return (1);
}
