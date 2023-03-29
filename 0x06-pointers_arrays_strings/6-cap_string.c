#include "main.h"

/**
 * isseparatorc - check if @char is separator character
 * @c: the char to check
 * Return: 0 if @char is not separator otherwise 1
 */
int isseparatorc(char c)
{
	char *sep = " \t\n,;.!?\"(){}";

	for (; *sep; sep++)
	{
		if (c == *sep)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * cap_string - capitalize all words of a string
 * @str: reference to a string
 * Return: @str
 */
char *cap_string(char *str)
{
	int i;
	char c, cap = 1;

	for (i = 0; (c = *(str + i)); i++)
	{
		if (c >= 'a' && c <= 'z' && cap)
		{
			*(str + i) = c - 32;
			cap = 0;
			continue;
		}

		cap = isseparatorc(c);
	}
	return (str);
}
