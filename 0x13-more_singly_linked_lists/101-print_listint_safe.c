#include "lists.h"
#include <stdio.h>

size_t unique_nodes_count(const listint_t *list_head);
size_t safe_listint_print(const listint_t *list_head);

/**
 * unique_nodes_count - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @list_head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t unique_nodes_count(const listint_t *list_head)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 1;

	if (list_head == NULL || list_head->next == NULL)
		return (0);

	tortoise = list_head->next;
	hare = (list_head->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = list_head;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

			return (nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 * safe_listint_print - Prints a listint_t list safely.
 * @list_head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t safe_listint_print(const listint_t *list_head)
{
	size_t nodes, index = 0;

	nodes = unique_nodes_count(list_head);

	if (nodes == 0)
	{
		for (; list_head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)list_head, list_head->n);
			list_head = list_head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)list_head, list_head->n);
			list_head = list_head->next;
		}

		printf("-> [%p] %d\n", (void *)list_head, list_head->n);
	}

	return (nodes);
}
