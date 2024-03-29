#include "hash_tables.h"

/**
 * hash_table_set - adds an element to hash table
 *
 * @ht: pointer to hash table
 * @key: key of hash
 * @value: value to store
 *
 * Return: 1 if success, 0 if fails.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *new_node = malloc(sizeof(hash_node_t));



	if (new_node == NULL)
		return (0);

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = NULL;

	if (ht->array[index] != NULL)
		new_node->next = ht->array[index];

	ht->array[index] = new_node;

	return (1);
}
