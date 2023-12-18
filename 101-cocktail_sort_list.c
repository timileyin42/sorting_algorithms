#include "sort.h"

/**
 * swap_list - swaps the elements of the list
 *
 * @ptr: first pointer
 * @ptr1: second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 * Return: no return
 */
void swap_list(listint_t **ptr, listint_t **ptr1, int n)
{
	listint_t *aux, *tmp;

	aux = *ptr;
	tmp = *ptr1;

	aux->next = tmp->next;
	tmp->prev = aux->prev;

	if (tmp->next)
		tmp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = tmp;

	aux->prev = tmp;
	tmp->next = aux;

	if (n == 0)
		*ptr = tmp;
	else
		*ptr1 = aux;
}

/**
 * increase_sort - move the bigger numbers to the end
 *
 * @ptr: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			swap_list(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * decrease_sort - moves the smaller numbers to the start
 *
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			swap_list(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
		}
		aux = aux->prev;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order using the
 * Cocktail shaker sort algorithm
 *
 * @list: head of the linked list
 * Return: no return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit, *limit1, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit = limit1 = NULL;
	ptr = *list;

	do {
		increase_sort(&ptr, &limit, list);
		decrease_sort(&ptr, &limit1, list);
	} while (limit != limit1);
}
