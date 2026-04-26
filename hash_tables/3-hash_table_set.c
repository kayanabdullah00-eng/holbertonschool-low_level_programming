#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_value - updates value of an existing key
 * @node: node to update
 * @value: new value
 *
 * Return: 1 if success, 0 if fail
 */
int update_value(hash_node_t *node, const char *value)
{
	char *dup;

	dup = strdup(value);
	if (dup == NULL)
		return (0);

	free(node->value);
	node->value = dup;

	return (1);
}

/**
 * create_node - creates a new node
 * @key: key
 * @value: value
 *
 * Return: pointer to new node or NULL
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);

	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	return (node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (update_value(node, value));
		node = node->next;
	}

	node = create_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
