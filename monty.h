#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t **stack;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** Processes the opcode and chooses the appopriate function */
void process_opcode(char *opcode_str, int fileline);

void (*get_func(char *opcode))(stack_t **stack, unsigned int);

/** Convert opcode to array which is easier to operate on*/
char **split_string(char *str);
void _strcpy(char *dest, char *src);

/** Instructions */
stack_t *_push(char **arr, unsigned int line_number);
void print_all(stack_t **h, unsigned int line_number);
void print_top(stack_t **h, unsigned int line_number);
void pop(stack_t **h, unsigned int line_number);
void swap(stack_t **h, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

stack_t *add_dnodeint(stack_t **head, const int n);

void handle_free(char **arr);

#endif /*MONTY_H*/
