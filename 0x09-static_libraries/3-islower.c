#include "main.h"

/**
 * _islower - function checking if @i is a lowercase character
 *
 * @i: is the character to check
 *
 * Return: 1 if @i is lowercase, and returns 0 otherwise
 */
int _islower(int i)
{
	if (i >= 97 && i <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
