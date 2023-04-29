#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a list
 *
 * @head: pointer to head of 1st node in the list
 *
 * @n: content of the list
 *
 * Return: address of the new element else NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;

	node = malloc(sizeof(listint_t));

	if (!node)
		return (NULL);
	node->n = n;

	if (*head)
		node->next = *head;

	*head = node;

	return (node);
}
