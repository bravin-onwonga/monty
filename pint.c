#include "monty.h"

void pop_top(stack_t **h, unsigned int line_number);

/**
 * print_top - prints the value at the top of the stack,
 *		followed by a new line.
 *
 * @h: head node
 * @line_number: line number of command in file
 */

void print_top(stack_t **h, unsigned int line_number)
{
	stack_t *temp;

	if (!h || !(*h))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *h;
	fprintf(stdout, "%d\n", temp->n);
	free(temp);
}

/**
 * pop_top - pops the value at the top of the stack
 *
 * @h: head node
 * @line_number: line number of command in file
 */

void pop_top(stack_t **h, unsigned int line_number)
{
	stack_t *temp;

	if (!h || !(*h))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *h;

	*h = temp->next;
	(*h)->prev = NULL;

	free(temp);
}
