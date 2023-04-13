#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 *
 * @b: size of memory allocated
 *
 * Description: allocates memory of size @b and returns
 * address to the memory else exits with status code 98
 *
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (!ptr)
		exit(98);
	return (ptr);
}
