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
	size_t i, counter = 0, size = 5;
	void **pointers;

	if (!head)
		return (0);

	/* init pointers list */
	pointers = calloc(size, sizeof(void *));
	if (!pointers)
		exit(98);

	while (head)
	{
		/* check if current node is not printed before */
		for (i = 0; i < counter; i++)
			if (pointers[i] == (void *)head)
				goto loop_detected;

		printf("[%p] %d\n", (void *)head, head->n);

		/* push the current node pointer to the pointers list */
		pointers[counter++] = (void *)head;
		head = head->next;

		/* if pointers list is full then reallocate larger memory */
		if (counter >= size)
		{
			size += 5;
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
	return (counter);
}
