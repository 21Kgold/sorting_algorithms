#include "sort.h"

/**
 * cocktail_sort_list - function that implements coctail sort
 * or double bubble sort
 * @list: list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *temp = NULL;
	int swap = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = *list;
	while (swap == 1)
	{
		swap = 0;
		while (current->next != NULL)
		{
			temp = current;
			if (current->n > current->next->n)
		{
		if (current->prev != NULL)
		{
			temp->prev->next = temp->next;
		}
		temp->next->prev = temp->prev;
		temp->next = temp->next->next;
		if (current->prev == NULL)
		{
			temp->prev = temp->next->prev;
			*list = temp->prev;
		}
		else
		{
			temp->prev = temp->prev->next;
		}
		temp->prev->next = temp;
		if (temp->next != NULL)
		{
			temp->next->prev = temp;
		}
		swap = 1;
		print_list(*list);
		}
		else
		{
			current = current->next;
		}
	}
	while (current->prev != NULL)
	{
		temp = current;
		if (current->n < current->prev->n)
	{
		swap = swap_opposite(list, current);
	}
	else
	{
		current = current->prev;
	}
	}
}
}

int swap_opposite(listint_t **list, listint_t *current)
{
	listint_t *temp = NULL;
	int swap = 0;

	temp = current;
	temp->prev->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = temp->prev;
	}
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
	temp->next->prev = temp;
	if (temp->prev != NULL)
	{
		temp->prev->next = temp;
	}
	else
	{
		*list = temp;
	}
	swap = 1;
	print_list(*list);
	return (swap);
}
