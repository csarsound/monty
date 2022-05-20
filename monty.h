#ifndef monty_H
#define monty_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stackk_s - doubly linked list representation of a stack (or queue)
 * @prev: pointer for the head of nodo
 * @next: pointr for the final of nodo
 * @n: integer
 */
typedef struct stackk_s
{
	int n;
	struct stackk_s *prev;
	struct stackk_s *next;
} stackk_t;

/**
 * struct instruction_s - opcode and its function
 * @f: pointerf
 * @opcode: the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stackk_t **stackk, unsigned int line_number);
} instruction_t;

/**
 * struct globalizator - helps to make global variables
 * @head: head of the stackk
 * @line_number: track of the line of the opcode
 * @buffer: buffer where we save the data
 * @n: value
 * @fptr: pointer to the file descriptor
 */
typedef struct globalizator
{
	stackk_t *head;
	unsigned int line_number;
	char *buffer;
	char *n;
	FILE *fptr;
} global_variables;

extern global_variables globv;

int get_operator(char *opcode);
void set_to_global(void);
void push_func(stackk_t **stack, unsigned int line_number);
stackk_t *add_element(stackk_t **head, unsigned int n);
void free_stack(stackk_t *head);
void pall_func(stackk_t **stack, unsigned int line_number);


#endif
