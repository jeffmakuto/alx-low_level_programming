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
	size_t count = 0;
	const listint_t *current_node = head;
	const listint_t *prev_nodes[1024];
	size_t i, j;

	while (current_node != NULL)
	{
		printf("[%p] %d\n", (void *)current_node, current_node->n);
		count++;

		if (count == 1024)
			exit(98);

		prev_nodes[count - 1] = current_node;
		current_node = current_node->next;

		for (i = 0; i < count - 1; i++)
			if (prev_nodes[i] == current_node)
			{
				for (j = 0; j <= i; j++)
					printf("-> [%p] %d\n", (void *)prev_nodes[j], prev_nodes[j]->n);
				exit(98);
			}
	}

	return (count);
}
