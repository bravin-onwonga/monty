#include "monty.h"

stack_t *add_dnodeint(stack_t **head, const int n);
char *arr_to_str(char **arr);

/**
 * print_all - prints all the elements of a dlistint_t list.
 *
 * @h: head node
 * @line_number: line number of command in file
 * Return: the number of nodes
 */

void print_all(stack_t **h, unsigned int line_number __attribute__((unused)))
{
	stack_t *curr;

	if (h)
	{
		curr = *h;

		while (curr != NULL)
		{
			printf("%d\n", curr->n);
			curr = curr->next;
		}
	}
}

/**
 * _push - adds a new element on top of a stack
 *
 * @arr: arr of push command and integer to be added
 * @line_number: line number of command in file
 * Return: pointer to head node of updated stack
 */

stack_t *_push(char **arr, unsigned int line_number)
{
	int j, n;
	char *s;

	if (arr[1])
	{
		s = arr[1];
		for (j = 0; s[j] != '\0'; j++)
		{
			if (s[j] < '0' || s[j] > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		n = atoi(s);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = add_dnodeint(stack, n);

	return (*stack);
}

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 *
 * @head: address head node
 * @n: integer element for the new node
 * Return: address of new node; otherwise NULL
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
		new_node->prev = NULL;
	}

	else
	{
		temp = *head;
		temp->prev = new_node;
		new_node->next = *head;
		*head = new_node;
		new_node->prev = NULL;
	}

	return (*head);
}
