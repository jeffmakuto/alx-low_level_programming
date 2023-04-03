#include <stddef.h>
/**
 * _strchr - locates a character in a string
 *
 * @s: the string
 *
 * @c: the character in the string @s
 *
 * Return: a pointer to first occurrence of @c in @s
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
