#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Jump search algorithm for a sorted linked list
 * @list: Pointer to the head of the linked list
 * @size: Number of nodes in the linked list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	listint_t *prev = NULL, *current = list;
	size_t i;

	if (list == NULL || size == 0)
		return (NULL);

	while (current && current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		prev = current;
		/* Move to the next block */
		for (i = 0; current && i < step; i++)
			current = current->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);
	/* Perform linear search within the identified block */
	while (prev && prev->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
