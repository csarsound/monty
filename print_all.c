#include "monty.h"

/**
* pall_func - print all the content
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (stack != NULL && tmp != NULL)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}
