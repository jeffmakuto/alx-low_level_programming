#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: double pointer to the head of list
 * @n: new integer added to the list
 * Return: address of new element or NULL if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}
