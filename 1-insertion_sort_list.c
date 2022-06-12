#include "sort.h"

/**
 * insertion_sort_list - function that sorts an array of numeric elements
 * in ascendant order.
 *
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *eval = (*list);
	listint_t *swap = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	while (eval != NULL)
	{
		swap = eval;
		while (eval->prev != NULL && eval->n < eval->prev->n)
		{
			swap->prev->next = swap->next;
			if (swap->next != NULL)
			{
				swap->next->prev = swap->prev;
			}
			swap->next = swap->prev;
			swap->prev = swap->prev->prev;
			swap->next->prev = swap;
			if (swap->prev != NULL)
			{
				swap->prev->next = swap;
			}
			else
			{
				*list = swap;
			}
			print_list(*list);
		}
		eval = eval->next;
	}
}
