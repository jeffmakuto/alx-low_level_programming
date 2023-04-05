#include "main.h"

/**
 * _sqrt_helper - finds the natural square root of a number recursively
 *
 * @n: number to find square root of
 *
 * @i: current integer to check as a possible square root
 *
 * Return: square root of n if n has natural root,
 * else -1
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	else if (i * i > n)
	{
		return (-1);
	}
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 *
 * @n: integer number
 *
 * Return: if n does not have a natural root, return -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}

	return (_sqrt_helper(n, 1));
}
