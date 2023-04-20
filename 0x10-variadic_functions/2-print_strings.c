#include <stdio.h>
#include <string.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings followed by a new line
 *
 * @separator: string to be printed between the strings
 *
 * @n: number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 1; i <= n; i++)
	{
		char *str = va_arg(args, char *);

		printf("%s", str ? str : "(nil)");

		if (separator && i != n)
			printf("%s", separator);
	}
	putchar('\n');

	va_end(args);
}
