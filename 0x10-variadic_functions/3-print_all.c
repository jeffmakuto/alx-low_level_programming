#include <stdio.h>
#include <string.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything as described in @format
 *
 * @format: a string that describes the types of arguments
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *sep = "", *str;
	va_list args;

	if (format)
	{
		va_start(args, format);
		while (format[i])
		{
			switch (format[i++])
			{
				case 'c':
					printf("%s%c", sep, va_arg(args, int));
					sep = ", ";
					break;
				case 's':
					str = va_arg(args, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", sep, str);
					sep = ", ";
					break;
				case 'i':
					printf("%s%i", sep, va_arg(args, int));
					sep = ", ";
					break;
				case 'f':
					printf("%s%f", sep, va_arg(args, double));
					sep = ", ";
					break;
				default:
					break;
			}
		}
		va_end(args);
	}
	putchar('\n');
}
