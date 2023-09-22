#include "sort.h"
/**
 * insertion_sort_list - insertion sort algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = NULL;
	while (*list != NULL)
	{
		current = *list;
		*list = (*list)->next;
		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			listint_t *tmp = sorted;

			while (tmp->next != NULL && tmp->next->n < current->n)
				tmp = tmp->next;
			current->next = tmp->next;
			current->prev = tmp;
			if (tmp->next != NULL)
				tmp->next->prev = current;
			tmp->next = current;
		}
		print_list(sorted);
	}
	*list = sorted;
}
