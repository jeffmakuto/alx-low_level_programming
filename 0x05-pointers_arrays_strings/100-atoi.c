#include "main.h"

/**
 * _atoi - converts a string to integer
 * @s: the reference string to be converted
 * Return: the integer value of the converted string
 */
int _atoi(char *s)
{
	int sign = 1;
	int num = 0;
	int started = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			num = num * 10 + (*s - '0');
			started = 1;
		}
		else if (started)
		{
			break;
		}
		s++;
	}
	return (num * sign);
}
