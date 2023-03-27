#include "main.h"

/**
 * _strlen - calculate the length of a string
 * @s: the string reference
 * Return: the length of @s
 */
int _strlen(char *s)
{
	int i = 0;
	char c = *s;

	while (c != '\0')
	{
		c = *(s + ++i);
	}
	return (i);
}
