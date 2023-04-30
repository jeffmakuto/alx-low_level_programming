#include "lists.h"

/**
 * listint_len - Returns number of elements in a linked list.
 *
 * @h: pointer to the head of the 1st node in a lined list
 *
 * Retun: no. of elements in a linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);

}
