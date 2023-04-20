#include <stdio.h>
#include <string.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers followed by a new line
 *
 * @separator: string to be printed between numbers
 *
 * @n: numbers of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 1; i <= n; i++)
	{
		printf("%d", va_arg(args, int));

		if (i != n && separator)
			printf("%s", separator);
	}
	putchar('\n');
	va_end(args);
}
