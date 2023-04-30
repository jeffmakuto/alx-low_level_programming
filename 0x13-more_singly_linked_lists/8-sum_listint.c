#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) of a linked list
 *
 * @head: pointer to the 1st node of the linked list
 *
 * Return: sum of the data (n), else 0
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	if (!head)
		return (0);
	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
