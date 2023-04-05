#include "main.h"

/**
 *is_prime_helper - helper function that recursively checks
 * if a number is prime
 *
 * @n: the number to check
 *
 * @i: the current divisor to try
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_helper(int n, int i)
{
	if (n <= 1)
	{
		return (0);
	}
	else if (i * i > n)
	{
		return (1);
	}
	else if (n % i == 0)
	{
		return (0);
	}
	else
	{
		return (is_prime_helper(n, i + 1));
	}
}

/**
 * is_prime_number - returns input integer of the prime number
 *
 * @n: the prime number
 *
 * Return: 1 if input integer is a prime number,
 * else 0
 */
int is_prime_number(int n)
{
	return (is_prime_helper(n, 2));
}
