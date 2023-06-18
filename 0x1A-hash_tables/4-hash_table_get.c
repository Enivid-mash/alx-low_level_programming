#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 *
 * @ht: pointer to hash table
 * @key: key of hash
 *
 * Return: value if success, NULL if fails.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *node = ht->array[index];


	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}

	return (NULL);
}
