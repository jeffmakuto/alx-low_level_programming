#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers using
 * linear search algorithm
 *
 * @array: pointer to 1st element of the array to search in
 *
 * @size: number of elements in array
 *
 * @value: value to search for
 *
 * Return: first index where value is located else -1, if
 * value not present in array or if array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (!array)
		return (-1);
	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%u] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
