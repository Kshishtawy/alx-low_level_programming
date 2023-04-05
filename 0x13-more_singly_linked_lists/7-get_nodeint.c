#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node at a given index in a linked list
 * @head: Pointer to the first node of the list
 * @index: Index of the node to return
 *
 * Return: Pointer to the node at the given index, or NULL if it does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *temp = head;

	while (temp != NULL && count < index)
	{
		temp = temp->next;
		count++;
	}

	if (count != index)
		return (NULL);

	return (temp);
}
