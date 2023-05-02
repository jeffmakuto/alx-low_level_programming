#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a linked list.
 
 * @head: a pointer to the 1st node of the list.
 
 * @index: the index of the node to return, starting at 0.
 *
 * Return: pointer to the nth node, or NULL if the node doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;
    listint_t *node;

    for (i = 0, node = head; node && i < index; i++, node = node->next)
        ;

    return (node ? node : NULL);
}
