#include "sort.h"

/**
 * swp_nodes -  Swap two nodes in a listint_t doble linked list
 * @h: A pointer to the head of the double linked list
 * @a: A pointer to the first node to swap
 * @b: The second node to swap
 */
void swp_nodes(listint_t **h, listint_t *a, listint_t *b)
{
	if (b->next)
		b->next->prev = a;
	if (a->prev)
		a->prev->next = b;
	else
		*h = b;
	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
	a = b->prev;
}

/**
 * insertion_sort_list - Sort double linked list of ints, print list each swap
 * @list: a pointer to the head of a double linked list of integer
 * Description: prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	for (i = (*list)->next; i; i = tmp)
	{
		tmp = i->next;
		while (i->prev && i->n < i->prev->n)
		{
			swp_nodes(list, i->prev, i);
			print_list((const listint_t *)*list);
		}
	}
}
