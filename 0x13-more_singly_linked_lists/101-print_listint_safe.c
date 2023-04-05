#include "lists.h"
#include <stdio.h>

/**
 * get_unique_nodes_in_loop - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t get_unique_nodes_in_loop(const listint_t *list_head)
{
	const listint_t *tortoise, *hare;
	size_t num_nodes = 1;

	/* Check if list is empty or has only one node */
	if (list_head == NULL || list_head->next == NULL)
		return (0);

	tortoise = list_head->next;
	hare = (list_head->next)->next;

	while (hare)
	{
		if (tortoise == hare) /* The tortoise and hare meet */
		{
			tortoise = list_head;

			/* Count the number of unique nodes until the meeting point */
			while (tortoise != hare)
			{
				num_nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;

			/* Count the number of nodes in the loop */
			while (tortoise != hare)
			{
				num_nodes++;
				tortoise = tortoise->next;
			}

			return (num_nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0); /* List is not looped */
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *list_head)
{
	size_t num_nodes, index = 0;

	num_nodes = get_unique_nodes_in_loop(list_head);

	if (num_nodes == 0) /* List is not looped */
	{
		for (; list_head != NULL; num_nodes++)
		{
			printf("Address[%p] Data[%d]\n", (void *)list_head, list_head->n);
			list_head = list_head->next;
		}
	}

	else /* List is looped */
	{
		for (index = 0; index < num_nodes; index++)
		{
			printf("Address[%p] Data[%d]\n", (void *)list_head, list_head->n);
			list_head = list_head->next;
		}

		printf("Loop starts at address [%p] with data [%d]\n", (void *)list_head, list_head->n);
	}

	return (num_nodes);
}
