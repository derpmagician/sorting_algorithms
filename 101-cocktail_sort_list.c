#include "sort.h"
/**
 * swaptoR - swaps nodes from left to right
 * @list: pointer to list
 * @head: pointer to head node
 * @aux: auxiliar pointer
 * Return: no return
 */
void swaptoR(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;
	else
		*list = aux;
	if (aux->next)
		aux->next->prev = head;
	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;
	head->prev = aux;
	print_list(*list);

}
/**
 * swaptoL - swaps nodes from right to left
 * @list: pointer to list
 * @head: pointer to head node
 * @aux: auxiliar pointer
 * Return: no return
 */
void swaptoL(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail sort ailgorithm
 * @list: pointer to the list head
 * Return: no return
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int keep_going = 1;

	if (list)
	{
		head = *list;
		while (keep_going != 0)
		{
			keep_going = 0;
			while (head->next)
			{
				if (head->n > head->next->n)
				{
					aux = head->next;
					swaptoR(list, head, aux);
					keep_going = 1;
				}
				else
					head = head->next;
			}
			if (keep_going == 0)
				break;
			keep_going = 0;
			while (head->prev)
			{
				if (head->prev->n > head->n)
				{
					swaptoL(list, head, aux);
					keep_going = 1;
				}
				else
					head = head->prev;
			}

		}
	}
}
