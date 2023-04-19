#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 *
 * @name: pointer to the name string
 *
 * @f: function pointer that formats the name string
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (f)
		(*f)(name);
}
