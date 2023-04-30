#include "lists.h"

/**
 * free_listint2 - frees a linked list
 *
 * @head: pointer to the 1st node of a linked list
 */
void free_listint2(listint_t **head)
{
	if (!head)
		return;

	while (*head)
	{
		listint_t *next = (*head)->next;

		free(*head);
		*head = next;

	}
}
