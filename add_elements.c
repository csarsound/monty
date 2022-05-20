#include "monty.h"

/**
* add_element - add a node at start of linked list
* @head: head of the linked list
* @n: number we want in new node
* Return: the address of the new element, or NULL if it failed
*/

stack_t *add_element(stack_t **head, unsigned int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
