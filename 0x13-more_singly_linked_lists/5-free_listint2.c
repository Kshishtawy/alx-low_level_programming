#include "lists.h"

/**
 * free_listint2 - Frees a linked list and sets the head to NULL.
 * @head: Double pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp, *current;

	if (head == NULL)
		return;

	current = *head;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*head = NULL;
}
