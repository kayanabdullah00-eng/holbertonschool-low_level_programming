#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to pointer of list
 * @idx: index to insert at
 * @n: value to store
 *
 * Return: address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	while (temp != NULL && i < idx)
	{
		if (i == idx - 1)
			break;
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = temp->next;
	new->prev = temp;

	if (temp->next != NULL)
		temp->next->prev = new;

	temp->next = new;

	return (new);
}
