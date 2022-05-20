#ifndef monty_H
#define monty_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @prev: pointer for the head of nodo
 * @next: pointr for the final of nodo
 * @n: integer
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @f: pointerf
 * @opcode: the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globalizator - helps to make global variables
 * @head: head of the stack
 * @line_number: track of the line of the opcode
 * @buffer: buffer where we save the data
 * @n: value
 * @fptr: pointer to the file descriptor
 */
typedef struct globalizator
{
	stack_t *head;
	unsigned int line_number;
	char *buffer;
	char *n;
	FILE *fptr;
} global_variables;

extern global_variables globv;

int is_number(char *s);
int get_operator(char *opcode);
void set_to_global(void);
void push_func(stack_t **stack, unsigned int line_number);
stack_t *add_element(stack_t **head, unsigned int n);
void free_stack(stack_t *head);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
int delete_node_at_index(stack_t **head, unsigned int index);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);

#endif
