#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings
 *
 * @s1: the first string to concatenate to.
 *
 * @s2: the second string to concatenate to @s1.
 *
 * @n: number of bytes to concatenate from @s2
 *
 * allocate new memory and concatenate @s1
 * and @n bytes of @s2. If @s1 0r @s2 is null then it
 * will be used as an empty string. If @n is greater than
 * @s2 then the entire @s2 will be used. The allocated
 * memory then null terminates.
 *
 * Return: pointer to a newly allocated space in memory,
 * which contains s1, followed by s2 else NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int len1, len2;

	/* Calculate s1 and s2 lenghths*/
	len1 = !s1 ? 0 : strlen(s1);
	len2 = !s2 ? 0 : strlen(s2);
	/* Calculate s2 needed length to copy*/
	len2 = n > len2 ? len2 : n;

	/* allocate memory */
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	/*set terminating null caharacter*/
	str[len1 + len2] = 0;

	/*copy s1 if its not NULL*/
	if (s1)
		strcpy(str, s1);
	/*copy required s2 length*/
	if (s2)
		strncpy(str + len1, s2, len2);
	return (str);
}
