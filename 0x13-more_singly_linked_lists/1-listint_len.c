#include "lists.h"

/**
 * listint_len - returns number of elements in a linked list
 *
 * @h: pointer to the head of the node
 *
 * Retun: integer
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
