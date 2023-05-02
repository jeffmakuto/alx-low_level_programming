#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list
 
 * @h: Pointer to the 1st node of the linked list
 *
 * Return: The number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
