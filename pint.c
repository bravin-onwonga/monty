#include "monty.h"

/**
 * print_top - prints the value at the top of the stack,
 *		followed by a new line.
 *
 * @h: head node
 * @line_number: line number of command in file
 */

void print_top(stack_t **h, unsigned int line_number)
{
	if (!h || !(*h))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*h)->n);
}
