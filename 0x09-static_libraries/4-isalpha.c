#include "main.h"

/**
 * _isalpha - check if @i is a alpha character
 *
 * @i: the character to check
 *
 * Return: 1 if @i is an alpha character
 * else return 0
 */
int _isalpha(int i)
{
	return ((i >= 97 && i <= 122) || (i >= 65 && i <= 90) ? 1 : 0);
}

