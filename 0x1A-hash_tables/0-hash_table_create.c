#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: the size of the array.
 *
 * Return: if an error occurs NULL, else a pointer to
 * the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
		return (NULL); /* Malloc failed */

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (!ht->array)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}
