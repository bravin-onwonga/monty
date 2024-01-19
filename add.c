#include "monty.h"

/**
 * add - swaps the two top values
 *
 * @stack: head node
 * @line_number: line number of command in file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *curr;
	int sum;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	next = curr->next;

	if (!next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = curr->n + next->n;

	pop(stack, line_number);
	pop(stack, line_number);

	*stack = add_dnodeint(stack, sum);
}
