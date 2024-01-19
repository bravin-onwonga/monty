#include "monty.h"

/**
 * swap - swaps the two top values
 *
 * @h: head node
 * @line_number: line number of command in file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *next, *curr;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	curr = *stack;

	next = temp->next;
	if (!next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	curr->next = next->next;
	curr->prev = next;

	if (next->next)
		next->next->prev = curr;

	next->next = temp;
	next->prev = NULL;

	*(stack) = next;
}
