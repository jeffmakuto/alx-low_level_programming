#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted
 * array using interpolation search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where the value is located,
 * or -1 if not present or if array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	while (low <= high)
	{
		pos = low + (((double)(high - low) / (array[high]
						- array[low])) * (value - array[low]));

		if (pos < size)
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}
		if (array[pos] == value)
			return ((int)pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	return (-1);
}
