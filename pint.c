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
	stack_t *temp;

	if (!h || !(*h))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *h;
	printf("%d\n", temp->n);
	free(temp);
}
