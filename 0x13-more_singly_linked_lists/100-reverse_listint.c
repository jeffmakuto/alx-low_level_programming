#include "lists.h"

/**
 * reverse_listint - reverses a liked list
 *
 * @head: pointer to the 1st node list pointer
 *
 * Return: pointer to the 1st node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next, *prev = NULL;

	if (!head)
		return (NULL);

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
