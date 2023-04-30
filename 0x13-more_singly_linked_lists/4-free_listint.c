#include "lists.h"

/**
 * free_listint - frees a linked list
 *
 * @head: pointer to the 1st node of the list
 */
void free_listint(listint_t *head)
{
	while (head)
	{
		listint_t *next = head->next;

		free(head);

		head = next;
	}
}
