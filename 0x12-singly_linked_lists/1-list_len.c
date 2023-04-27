#include "lists.h"

/**
 * list_len - returns number of elements in a linked list
 *
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
	int count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
