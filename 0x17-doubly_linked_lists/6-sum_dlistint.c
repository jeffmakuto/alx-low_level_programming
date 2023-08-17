#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all data (n) in a linked list
 * @head: A pointer to the head of the linked list.
 * Return: The sum of all data values, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}

