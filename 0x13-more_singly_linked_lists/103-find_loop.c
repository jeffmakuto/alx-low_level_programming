#include "lists.h"

/**
 * find_listint_loop - find the first node of the loop in linked list
 * @head: pointer to the first node in the linked list
 *
 * Return: pointer to the first node of the loop otherwise NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (!head || !head->next)
		return (NULL);

	/* search for a loop */
	do
		slow = slow->next, fast = fast->next->next;
	while (fast && fast->next && slow != fast);

	/* if loop exists */
	if (slow == fast && slow)
	{
		slow = head;

		/* if collide at first node */
		if (slow == fast)
			while (fast->next != slow)
				fast = fast->next;
		else
			while (slow->next != fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
		return (fast->next);
	}

	return (NULL);
}
