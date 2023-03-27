#include "main.h"

/**
 * _strcpy - copies the string from @src to @dest
 * @dest: the reference to copy to
 * @src: the reference to copy from
 * Return: the reference of @dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	char c;

	i = 0;
	while (1)
	{
		c = *(src + i);
		*(dest + i++) = c;

		if (c == '\0')
		{
			break;
		}
	}
	return (dest);
}
