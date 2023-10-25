#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - Function that swaps two nodes in a doubly....
 * linked list.......
 *
 * @list: doubly linked list.....
 * @node1: pointer to the node to swap....
 * @node2: pointer to the node to swap.....
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked
 * list of integers in ascending order using the Cocktail
 * shaker sort algorithm
 *
 * @list: doubly linked list
 * Return: Void (Nothing)
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = NULL, *curr_node, *end = NULL;
	int swap = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swap == 0)
	{
		swap = 1;
		curr_node = *list;
		while (curr_node->next != end)
		{
			if (curr_node->n > curr_node->next->n)
			{
				swap_nodes(list, curr_node, curr_node->next);
				print_list(*list);
				swap = 0;
			}
			else
				curr_node = curr_node->next;
		}
		end = curr_node;
		if (swap == 1)
			break;
		swap = 0;

		curr_node = curr_node->prev;
		while (curr_node->prev != head)
		{
			if (curr_node->n < curr_node->prev->n)
			{
				swap_nodes(list, curr_node->prev, curr_node);
				print_list(*list);
				swap = 0;
			}
			else
				curr_node = curr_node->prev;
		}
		head = curr_node;
	}
}
