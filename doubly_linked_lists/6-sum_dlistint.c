#include "lists.h"

/**
 * sum_dlistint - returns the sum of all n in a dlistint_t list
 * @head: pointer to list
 *
 * Return: sum of all nodes, or 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
