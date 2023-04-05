#include "main.h"

/**
 * factorial - returns the factorial of a given number
 *
 * @n: the factorial number
 *
 * factorial of 0 is 1
 *
 * Return: Integer and if n is lower than 0, return -1
 * to indicate error
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}
