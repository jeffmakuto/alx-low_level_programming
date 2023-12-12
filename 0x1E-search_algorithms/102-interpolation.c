#include "search_algos.h"

/**
 * interpolation_search - Interpolation search algorithm
 *
 * @array: input array (sorted in ascending order)
 * @size: size of array
 * @value: value to search
 * Return: index of the number, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, pos;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos = low + (((double)(high - low) / (array[high]
						- array[low])) * (value - array[low]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
		{
			printf("Found %d at index: %lu\n", value, pos);
			return (pos);
		}

		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	printf("Value checked array[%lu] is out of range\n", pos);
	printf("Found %d at index: -1\n", value);
	return (-1);
}
