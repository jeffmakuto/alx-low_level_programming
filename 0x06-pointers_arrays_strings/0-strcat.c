#include "main.h"

/**
 * _strcat - concatenates strings @dest and @src to @dest
 *
 * @dest: the string to append @src to
 *
 * @src: the string to be appended to @dest
 *
 * Return: a pointer to @dest
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	/* move dest pointer to end of string */
	for (; *dest; dest++)
	{
		/* empty */
	}

	/* copy from src to dest */
	for (; *src; src++, dest++)
	{
		*dest = *src;
	}

	/* set null char at the new end */
	*dest = 0;

	return (p);
}
