#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocate memory for array of members
 * @nmemb: the number of members
 * @size: the size of one member
 *
 * Return: pointer to the allocated memory otherwise NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	int len = nmemb * size;

	if (!len)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);

	memset(ptr, 0, len);
	return (ptr);
}
