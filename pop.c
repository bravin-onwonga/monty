#include "monty.h"

/**
 * pop - pops the value at the top of the stack
 *
 * @h: head node
 * @line_number: line number of command in file
 */

void pop(stack_t **h, unsigned int line_number)
{
	/* stack_t *temp; */

	if (!h || !(*h))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* temp = *h; */

	*h = (*h)->next;
	if (*h)
		(*h)->prev = NULL;

	*stack = *h;
}
