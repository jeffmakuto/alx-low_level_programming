#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list
 *
 * @head: pointer to the node head in a list
 *
 * @str: string in the node
 *
 * Return: address of the new element, or NULL otherwise
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node;

	if (!head)
		return (NULL);
	node = malloc(sizeof(list_t));

	if (!node)
		return (NULL);

	node->str = strdup(str);

	if (!node->str)
	{
		free(node);
		return (NULL);
	}

	node->len = strlen(str);

	if (!*head)
	{
		*head = node;
	}
	else
	{
		list_t *h = *head;

		while (h->next)
			h = h->next;
		h->next = node;
	}

	return (node);
}
