#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Jump search algorithm
 *
 * @array: input array
 * @size: size of array
 * @value: value to search
 * Return: index of the number, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size), prev = 0, current = 0, i;

	if (array == NULL || size == 0)
		return (-1);

	do {
		printf("Value checked array[%lu] = [%d]\n", current,
				array[current]);
		if (array[current] == value)
			return (current);
		prev = current;
		current += step;
	} while (current < size && array[current] < value);
	printf("Value found between indexes [%lu] and [%lu]\n", prev, current);

	for (i = prev; i <= current && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
	}
	return (-1);
}
