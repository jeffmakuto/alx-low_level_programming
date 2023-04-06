#include <string.h>

/**
 * _strpbrk - find first accurrence for any char in @accept found in @s
 * @s: the reference to string to be scanned
 * @accept: chars to scan for in @s
 * Return: pointer of first accurred char in @accept found in @s
 *         otherwise return Null
 */
char *_strpbrk(char *s, char *accept)
{
	for (; *s; s++)
		if (strchr(accept, *s))
			return (s);

	return (NULL);
}
