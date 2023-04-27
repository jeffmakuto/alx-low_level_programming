#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list
 *
 * @head: pointer to the head of a node
 *
 * @str: string elements of a node
 *
 * Return: address of the new element, or NULL otherwise
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;

	if (!head)
		return (NULL);

	node = malloc(sizeof(list_t));

	if (!node)
		return (NULL);

	node->str = strdup(str);

	if (!node->str)
	{	free(node);

		return (NULL);
	}

	node->len = strlen(str);
	node->next = *head;
	*head = node;

	return (node);
}
