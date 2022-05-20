#include "monty.h"

/**
* get_op - select the operator to call a function
* @opcode: string we want to evaluate to get the operator
* Return: 0 on success, exit if it get a invalid instruction
*/

int get_operator(char *opcode)
{
	int i;
	instruction_t op[] = {
		{"push", push_func},
		{"pall", pall_func},

		{NULL, NULL}
	};

	for (i = 0; op[i].opcode && opcode; i++)
		if (!strcmp(opcode, op[i].opcode))
		{
			op[i].f(&(globv.head), globv.line_number);
			return (0);
		}

	fprintf(stderr, "L%d: unknown instruction %s", globv.line_number, opcode);
	exit(EXIT_FAILURE);
}
