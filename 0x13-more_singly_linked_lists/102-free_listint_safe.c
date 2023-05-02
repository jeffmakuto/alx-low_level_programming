#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - free all nodes in linked list (safe)
 *
 * @h: pointer to the pointer of the first node in the list
 *
 * Return: the size of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 1, count = 0, i;
	listint_t *node;
	void **pointers;

	pointers = calloc(size, sizeof(void *));
	if (!pointers)
		return (0);

	while (h && *h)
	{
		node = *h;
		for (i = 0; i < count; i++)
			if (node == pointers[i])
				goto end;
		pointers[count++] = node;
		*h = node->next;
		node->next = NULL;
		free(node);
		if (count >= size)
		{
			size *= 2;
			pointers = realloc(pointers, size * sizeof(void *));
			if (!pointers)
				return (0);
		}
	}
end:
	*h = NULL;
	free(pointers);
	return (count);
}
