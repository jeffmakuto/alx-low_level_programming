#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a linked list
 *
 * @head: pointer to the head of the 1st node in the list
 *
 * @n: content of the list
 *
 * Return: address of the new element, else NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *last_node;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	last_node = *head;

	while (last_node->next)
		last_node = last_node->next;

	last_node->next = new_node;

	return (new_node);
}
