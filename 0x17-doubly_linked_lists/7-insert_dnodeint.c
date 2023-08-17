#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position in a dlistint_t list
 * @h: a pointer to a pointer to the head of the linked list.
 * @idx: The index at which the new node should be inserted.
 * @n: the value to be stored in the new node.
 * Return: the address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	dlistint_t *current = *h;
	unsigned int count = 0;

	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *h;
		if (*h)
			(*h)->prev = new;
		*h = new;
		return (new);
	}

	while (current)
	{
		if (count == idx - 1)
		{
			new->prev = current;
			new->next = current->next;
			if (current->next)
				current->next->prev = new;
			current->next = new;
			return (new);
		}
		current = current->next;
		count++;
	}
	free(new);
	return (NULL);
}

