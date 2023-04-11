#include <stdlib.h>
#include <string.h>

/**
 * create_array - creates an array of chars, and initializes
 * it with a specific char
 *
 * @size: size of array
 *
 * @c: byte to initialize the array
 *
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *str;

	if (size == 0)
	{
		return (NULL);
	}

	str = malloc(size);

	if (str != NULL)
	{
		memset(str, c, size);
	}

	return (str);
}
