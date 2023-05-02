#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 *
 * @head: pointer to head of list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, count = 0, size = 1;
	void **pointers;

	if (!head)
		return (0);

	pointers = malloc(size * sizeof(void *));
	if (!pointers)
		exit(98);

	while (head)
	{
		for (i = 0; i < count; i++)
			if (pointers[i] == (void *)head)
				goto loop_detected;

		printf("[%p] %d\n", (void *)head, head->n);

		pointers[count++] = (void *)head;
		head = head->next;

		if (count >= size)
		{
			size *= 2;
			pointers = realloc(pointers, size * sizeof(void *));
			if (!pointers)
				exit(98);
		}
	}

	goto complete;

loop_detected:
	printf("-> [%p] %d\n", (void *)head, head->n);

complete:
	free(pointers);
	return (count);
}

