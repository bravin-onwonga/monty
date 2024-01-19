#include "monty.h"

/**
 * pop_top - pops the value at the top of the stack
 *
 * @h: head node
 * @line_number: line number of command in file
 */

void pop(stack_t **h, unsigned int line_number)
{
	if (!h || !(*h))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*h = (*h)->next;
	if (*h)
		(*h)->prev = NULL;
}
