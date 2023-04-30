#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 *
 * @head: pointer to the first node of the linked list
 *
 * @idx: index of the list where the new node should be added
 *
 * @n: integer value of the node
 *
 * Return: the address of the new node, else NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *last_node;
	unsigned int i;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;

	if (!idx)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	last_node = *head;

	for (i = 0; i < idx - 1 && last_node; i++)
	{
			last_node = last_node->next;
	}

	if (!last_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = last_node->next;
	last_node->next = new_node;

	return (new_node);
}
