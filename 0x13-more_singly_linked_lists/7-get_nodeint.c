#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 *
 * @head: pointer to the head of the linked list
 *
 * @index: index of the node to return (starting from 0)
 *
 * Return: pointer to the node at the specified index,
 * or NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current = head;

	for (i = 0; current && i < index; i++)
		current = current->next;

	if (i != index || !current)
		return NULL;

	return current;
}
