#include "monty.h"

/**
* swap_func - swaps the two top elements
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *tmpn = NULL, *tmph = *stack;
	unsigned int counter;

	for (counter = 0; tmp != NULL; counter++)
		tmp = tmp->next;

	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmpn = tmp->next;
	tmp->next = tmpn->next;
	tmp->prev = tmpn;
	tmpn->next = tmph;
	tmpn->prev = tmph->prev;

	*stack = tmpn;
}
