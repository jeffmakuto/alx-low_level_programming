#include "main.h"

/**
 * _atoi - convert string to integer
 * @s: the reference to string
 * Return: the first continues integer in @s else 0
 */
int _atoi(char *s)
{
	char sign = 1, c;
	unsigned int i = 0, n = 0;

	while (1)
	{
		c = *(s + i++);
		if (c == '\0')
			break;

		if (c == '-')
		{
			sign *= -1;
		}
		else if (c >= '0' && c <= '9')
		{
			c -= '0';
			n *= 10;
			n += c;
		}
		else if (n > 0)
		{
			break;
		}
	}

	n *= sign;
	return (n);
}
