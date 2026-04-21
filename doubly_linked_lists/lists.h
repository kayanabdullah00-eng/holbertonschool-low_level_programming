#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to previous node
 * @next: points to next node
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/* print */
size_t print_dlistint(const dlistint_t *h);

/* length */
size_t dlistint_len(const dlistint_t *h);

/* add at beginning */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);

/* add at end */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/* free list */
void free_dlistint(dlistint_t *head);

/* get node */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/* insert at index */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);

/* delete at index */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif
