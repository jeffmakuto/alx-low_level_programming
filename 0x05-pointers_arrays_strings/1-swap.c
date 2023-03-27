#include "main.h"

/**
 * swap_int - swap the values of @a and @b
 * @a: the reference to 1st variable
 * @b: the reference to 2nd variable
 * Return: Void
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}
