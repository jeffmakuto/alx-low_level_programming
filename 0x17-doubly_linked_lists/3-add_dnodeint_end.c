#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: double pointer to the head of a list
 * @n: new integer to add
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	dlistint_t *current = *head;

	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
	return (new);
}
