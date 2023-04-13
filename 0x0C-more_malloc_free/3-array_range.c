#include <stdlib.h>

/**
 * array_range - create array of integers in range [@min, @max]
 * @min: the int to begin with
 * @max: the int to end with
 *
 * Return: pointer to the generated array
 */
int *array_range(int min, int max)
{
	int *ptr, i;

	/* validate inputs */
	if (min > max)
		return (NULL);

	/* allocate memory for the array */
	ptr = calloc(max - min + 1, sizeof(int));
	if (!ptr)
		return (NULL);

	/* generate the array elements */
	for (i = min; i <= max; i++)
		ptr[i - min] = i;

	return (ptr);
}
