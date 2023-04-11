#include <string.h>
#include <stdlib.h>

/**
 * str_concat - concat s2 to s1 at new allocated memory
 *
 * @s1: concated string first part
 *
 * @s2: convated string second part
 *
 * Return: Pointer to the allocated memory otherwise NULL
 */
char *str_concat(char *s1, char *s2)
{
	int len1, len2;
	char *str;

	len1 = !s1 ? 0 : strlen(s1);
	len2 = !s2 ? 0 : strlen(s2);

	str = malloc(len1 + len2 + 1);
	if (str == NULL)
	{
		return (NULL);
	}

	if (s1 != NULL)
	{
		strcpy(str, s1);
	}

	if (s2 != NULL)
	{
		strcpy(str + len1, s2);
	}

	str[len1 + len2] = 0;

	return (str);
}

