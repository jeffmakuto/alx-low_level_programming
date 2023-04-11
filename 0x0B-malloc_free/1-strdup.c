#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of string given as a parameter
 *
 * @str: copy of the string
 *
 * Return: pointer to the duplicated string, or NULL if memory is
 * insufficient
 */
char *_strdup(char *str)
{
	int len;
	char *dup;

	if (str == NULL)
	{
		return (NULL);
	}

	len = strlen(str);
	dup = malloc(len + 1);

	if (dup == NULL)
	{
		return (NULL);
	}

	strcpy(dup, str);
	dup[len] = 0;

	return (dup);
}
