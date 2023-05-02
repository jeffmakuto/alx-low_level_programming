#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a linked list
 *
 * @head: pointer to pointer to the first node of the list
 *
 * @index: index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *last;
	unsigned int count;

	if (!*head)
		return (-1);

	if (!index)
	{
		current = *head;
		*head = (*head)->next;
		free(current);

		return (1);
	}

	current = *head;
	count = 0;

	while (current && count < index)
	{
		last = current;
		current = current->next;
		count++;
	}

	if (!current)
		return (-1);

	last->next = current->next;
	free(current);

	return (1);
}
