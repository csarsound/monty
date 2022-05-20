#include "monty.h"

/**
* pop_func - deletes the top element of the stack
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void pop_func(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	delete_node_at_index(stack, 0);
}
