#include "lists.h"

/**
 * get_sum - calculates the sum of all the data in a linked list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int get_sum(listint_t *head)
{
    int total_sum = 0;
    listint_t *temp = head;

    while (temp != NULL)
    {
        total_sum += temp->n;
        temp = temp->next;
    }

    return total_sum;
}
