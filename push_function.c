#include "monty.h"

/**
* push_func - function to add a number at the start
* @stack: pointer to the head of the stack
* @line_number: number of the line of the opcode
*/

void push_func(stack_t **stack, unsigned int line_number)
{
	unsigned int number;

	if (!is_number(globv.n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(globv.buffer);
		fclose(globv.fptr);
		free_stack(globv.head);
		exit(EXIT_FAILURE);
	}

	number = atoi(globv.n);
	add_element(stack, number);
}
