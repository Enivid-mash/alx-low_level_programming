#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 *
 * @ht: pointer to hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	int first_pair = 1;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *node = ht->array[i];

		while (node != NULL)
		{
			if (!first_pair)
				printf(", ");

			printf("'%s': '%s'", node->key, node->value);

			first_pair = 0;
			node = node->next;
		}
	}

	printf("}\n");
}
